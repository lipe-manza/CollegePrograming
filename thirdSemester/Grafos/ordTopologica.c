#include <stdio.h>

#define MAX 100

typedef enum
{
    BRANCO,
    CINZA,
    PRETO
} Cor;

Cor cor[MAX];
int dist[MAX];
int p[MAX]; // 🔥 predecessor

int adj[MAX][MAX];
int n;

int fila[MAX];
int inicio, fim;

void bfs(int s)
{
    inicio = 0;
    fim = 0;

    fila[fim++] = s;
    cor[s] = CINZA;
    dist[s] = 0;
    p[s] = -1; // origem não tem pai

    while (inicio < fim)
    {
        int u = fila[inicio++];

        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] && cor[v] == BRANCO)
            {
                fila[fim++] = v;
                cor[v] = CINZA;
                dist[v] = dist[u] + 1;
                p[v] = u; // guarda de onde veio
            }
        }

        cor[u] = PRETO;
    }
}

// imprime caminho da origem até v
void caminho(int origem, int v)
{
    if (v == origem)
    {
        printf("%d ", origem);
    }
    else if (p[v] == -1)
    {
        printf("sem caminho");
    }
    else
    {
        caminho(origem, p[v]);
        printf("%d ", v);
    }
}

int main()
{
    n = 7;

    // inicializa
    for (int i = 0; i < n; i++)
    {
        cor[i] = BRANCO;
        dist[i] = -1;
        p[i] = -1;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    /*
        Grafo:

        0 → 1 → 3 → 4
        ↓    ↓
        2 → 5 → 6
    */

    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][3] = 1;
    adj[1][5] = 1;
    adj[2][5] = 1;
    adj[3][4] = 1;
    adj[5][6] = 1;

    int origem = 0;

    bfs(origem);

    printf("Caminho de %d ate 6:\n", origem);
    caminho(origem, 6);

    printf("\n");

    return 0;
}
