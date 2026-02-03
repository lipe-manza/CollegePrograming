#include <stdio.h>

int main()
{
    int x, ap, app, final;
    scanf("%d", &x);
    int *p = &x;
    int **pp = &p;
    ap = x;
    *p += 10;
    app = x;
    **pp += 10;
    final = x;
    printf("Valor inicial do tesouro: %d\n", ap);
    printf("Valor do tesouro usando mapa: %d\n", ap);
    printf("Valor do tesouro usando mapa depois de adicionarmos 10 moedas: %d\n", app);
    printf("Valor do tesouro usando mapa para o mapa: %d\n", app);
    printf("Valor do tesouro usando mapa para o mapa depois de adicionarmos 10 moedas: %d\n", final);

    return 0;
}