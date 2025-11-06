#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int c[4];
    int passos;
} Estado;

#define MAX_FILA 10000
Estado fila[MAX_FILA];
int inicio, fim;

bool visitado[10][10][10][10];

void fila_inicializar() {
    inicio = 0;
    fim = 0;
}

bool fila_vazia() {
    return inicio == fim;
}

bool fila_inserir(Estado e) {
    int proximo = (fim + 1) % MAX_FILA;
    if (proximo == inicio) return false;
    fila[fim] = e;
    fim = proximo;
    return true;
}

Estado fila_remover() {
    Estado e = fila[inicio];
    inicio = (inicio + 1) % MAX_FILA;
    return e;
}

int bfs(Estado inicial, Estado alvo) {
    fila_inicializar();

    if (visitado[inicial.c[0]][inicial.c[1]][inicial.c[2]][inicial.c[3]])
        return -1;

    visitado[inicial.c[0]][inicial.c[1]][inicial.c[2]][inicial.c[3]] = true;
    fila_inserir(inicial);

    int movimentos[2] = { 1, -1 };

    while (!fila_vazia()) {
        Estado atual = fila_remover();

        if (atual.c[0] == alvo.c[0] && atual.c[1] == alvo.c[1] &&
            atual.c[2] == alvo.c[2] && atual.c[3] == alvo.c[3])
            return atual.passos;

        for (int i = 0; i < 4; i++) {
            for (int m = 0; m < 2; m++) {
                Estado vizinho = atual;
                vizinho.c[i] = (vizinho.c[i] + movimentos[m] + 10) % 10;
                vizinho.passos++;

                int r0 = vizinho.c[0], r1 = vizinho.c[1], r2 = vizinho.c[2], r3 = vizinho.c[3];
                if (!visitado[r0][r1][r2][r3]) {
                    visitado[r0][r1][r2][r3] = true;
                    fila_inserir(vizinho);
                }
            }
        }
    }

    return -1;
}

int main() {
    int casos;
    scanf("%d", &casos);

    for (int c = 0; c < casos; c++) {
        int s[4], t[4], np;

        for (int i = 0; i < 4; i++) scanf("%d", &s[i]);
        for (int i = 0; i < 4; i++) scanf("%d", &t[i]);
        Estado inicio = { {s[0], s[1], s[2], s[3]}, 0 };
        Estado alvo = { {t[0], t[1], t[2], t[3]}, 0 };

        scanf("%d", &np);

        for (int i0 = 0;i0 < 10;i0++)
            for (int i1 = 0;i1 < 10;i1++)
                for (int i2 = 0;i2 < 10;i2++)
                    for (int i3 = 0;i3 < 10;i3++)
                        visitado[i0][i1][i2][i3] = false;

        for (int i = 0; i < np; i++) {
            int f[4];
            scanf("%d %d %d %d", &f[0], &f[1], &f[2], &f[3]);
            visitado[f[0]][f[1]][f[2]][f[3]] = true;
        }

        int res = bfs(inicio, alvo);
        printf("%d\n", res);
    }

    return 0;
}
