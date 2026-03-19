#include <stdio.h>
#include "graph.h"

int main(void){
    int option;
    int N, x, y, w;
    scanf("%d", &N);
    Graph *G;

    scanf("%d", &option);

    switch (option)
    {
        int x, y, w;
        case 0:
            G = MyGraph(N);
        case 1:

            // adicionamos

            scanf("%d %d %d", &x, &y, &w);
            add_edge(G, x, y, w);
            scanf("%d", &x, &y, &w);
            add_edge(G, x, y, w);
            scanf("%d", &x, &y, &w);
            add_edge(G, x, y, w);
            scanf("%d", &x, &y, &w);
            add_edge(G, x, y, w);
            break;

        case 2:
            break;

        default:
            printf("unrecognized option!\n");
    }

    print_info(G);
    remove_graph(&G);
    return 0;
}