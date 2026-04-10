#include <stdio.h>

#define MAX 100

// define estados do vértice
typedef enum
{
    BRANCO,
    CINZA,
    PRETO
} Cor;

Cor cor[MAX];
int inicio[MAX];
int fim[MAX];

int adj[MAX][MAX];
int tempo;
int n;

void dfs(int u)
{
    cor[u] = CINZA;
    inicio[u] = ++tempo;

    printf("Entrando no vertice %d (tempo=%d)\n", u, tempo);

    for (int v = 0; v < n; v++)
    {
        if (adj[u][v] == 1 && cor[v] == BRANCO)
        {
            printf("Aresta de arvore: %d -> %d\n", u, v);
            dfs(v);
        }
    }

    fim[u] = ++tempo;
    cor[u] = PRETO;

    printf("Saindo do vertice %d (tempo=%d)\n", u, tempo);
}

void dfsGeral()
{
    for (int i = 0; i < n; i++)
    {
        cor[i] = BRANCO;
        inicio[i] = 0;
        fim[i] = 0;
    }

    tempo = 0;

    for (int u = 0; u < n; u++)
    {
        if (cor[u] == BRANCO)
        {
            printf("\n--- Nova DFS a partir do vertice %d ---\n", u);
            dfs(u);
        }
    }
}

int main()
{
    n = 7;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    /*
        Grafo:

        0 → 1 → 3 → 4 → 1
        ↓    ↓
        2 → 5 → 6
    */

    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][3] = 1;
    adj[1][5] = 1;
    adj[2][5] = 1;
    adj[3][4] = 1;
    adj[4][1] = 1;
    adj[5][6] = 1;

    dfsGeral();

    return 0;
}
