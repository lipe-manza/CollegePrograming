#include <stdio.h>

#define MAX 100

// estados dos vértices
typedef enum
{
    BRANCO,
    CINZA,
    PRETO
} Cor;

Cor cor[MAX];
int dist[MAX];

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

    printf("Comecando BFS no vertice %d\n", s);

    while (inicio < fim)
    {
        int u = fila[inicio++];

        printf("Visitando vertice %d (dist=%d)\n", u, dist[u]);

        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] && cor[v] == BRANCO)
            {
                fila[fim++] = v;
                cor[v] = CINZA;
                dist[v] = dist[u] + 1;

                printf("  Descobriu %d a partir de %d\n", v, u);
            }
        }

        cor[u] = PRETO;
    }
}

void bfsGeral()
{
    for (int i = 0; i < n; i++)
    {
        cor[i] = BRANCO;
        dist[i] = -1;
    }

    for (int u = 0; u < n; u++)
    {
        if (cor[u] == BRANCO)
        {
            printf("\n--- Nova BFS a partir de %d ---\n", u);
            bfs(u);
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

    bfsGeral();

    return 0;
}
