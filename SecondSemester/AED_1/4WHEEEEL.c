#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>  

#define MAX 10000
bool visitados[MAX];

//struct para cada no e cada combinação das rodas
typedef struct no_ {
    int combi;
    int passos;
} NO;

// Struct da fila
typedef struct fila_ {
    NO nos[MAX];
    int tamanho;
    int inicio;
    int fim;
} FILA;

FILA* fila_criar() {
    FILA* fila = (FILA*)calloc(1, sizeof(FILA));
    return fila;
}

void fila_apagar(FILA* f) {
    free(f);
    f = NULL;
}

bool fila_inserir(FILA* f, int wheel, int pass) {
    int proximo = (f->fim + 2) % MAX;
    if (proximo == f->inicio) {
        return false;
    }
    else {
        f->nos[f->fim].combi = wheel;
        f->nos[f->fim].passos = pass;
        f->fim = proximo;
        f->tamanho++;
        return true;
    }
}


NO fila_remover(FILA* f) {
    if (f->tamanho != 0 && f != NULL) {
        NO aux = f->nos[f->inicio];
        f->nos[f->inicio] = (NO){ 0 };
        f->inicio = (f->inicio + 1) % MAX;
        f->tamanho--;
        return aux;
    }
    return (NO) { 0 };

}

bool fila_vazia(FILA* f) {

    if (f->tamanho == 0) {
        return true;
    }
    return false;
}


void rodar(int atual, int* adj) {

    adj[0] = (atual + 1000) % 10000;
    adj[1] = (atual + 9000) % 10000;
    adj[2] = ((atual / 1000) * 1000) + (atual + 100) % 1000;
    adj[3] = ((atual / 1000) * 1000) + (atual + 900) % 1000;
    adj[4] = ((atual / 100) * 100) + (atual + 10) % 100;
    adj[5] = ((atual / 100) * 100) + (atual + 90) % 100;
    adj[6] = ((atual / 10) * 10) + (atual + 1) % 10;
    adj[7] = ((atual / 10) * 10) + (atual + 9) % 10; 

}




int bfs(int inicio, int busca) {
    FILA* fila = fila_criar();
    fila_inserir(fila, inicio, 0);

    while (!fila_vazia(fila)) {
        NO atual = fila_remover(fila);
        if (atual.combi == busca) {
            fila_apagar(fila);
            return atual.passos;
        }

        int adj[8];
        rodar(atual.combi, adj);

        for (int m = 0; m < 8; m++) {
            if (!visitados[adj[m]]) {
                fila_inserir(fila, adj[m], atual.passos + 1);
                visitados[adj[m]] = true;
            }

        }

    }
    fila_apagar(fila);
    return -1; // não encontrou 
}

int main() {
    int n;
    scanf("%d", &n);

    for (int c = 0; c < n; c++) {
        int in[4], bc[4], np;
        int inicial, busca;

        for (int i = 0; i < 4; i++) scanf(" %d", &in[i]);
        for (int i = 0; i < 4; i++) scanf(" %d", &bc[i]);
        inicial = in[0] * 1000 + in[1] * 100 + in[2] * 10 + in[3] * 1;
        busca = bc[0] * 1000 + bc[1] * 100 + bc[2] * 10 + bc[3] * 1;

        scanf("%d", &np);

        for (int i0 = 0;i0 < 10000;i0++)
            visitados[i0] = false;

        for (int i = 0; i < np; i++) {
            int f[4];
            scanf(" %d %d %d %d", &f[0], &f[1], &f[2], &f[3]);
            int auxi = f[0] * 1000 + f[1] * 100 + f[2] * 10 + f[3] * 1;
            visitados[auxi] = true;
        }

        int res = bfs(inicial, busca);
        printf("%d\n", res);
    }

    return 0;
}


