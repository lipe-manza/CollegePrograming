#include <stdio.h>
int main()
{
    char nome[51];
    float final, nota_anterior;
    int faltas, extras;

    printf("nome:");
    scanf("%[^\n]", nome);
    printf("nota final:");
    scanf("%f", &final);
    if (final < 0 || final > 10)
    {
        printf("entrada invalida");
        return 0.;
    }
    printf("quantidade de faltas:");
    scanf("%d", &faltas);
    printf("atividades extras:");
    scanf("%d", &extras);

    if (extras < 0 || extras > 5)
    {

        printf("entrada invalida");
        return 0;
    }

    nota_anterior = final;
    if (extras >= 3 && final != 10)
    {

        final = final + 1.0;
    }

    if (faltas > 15 && final != 0)
    {

        final = final - 1.0;
    }

    if (final >= 9 && final <= 10)
    {
        printf("%s, %2f, %2f , desempenho excelente", nome, final, nota_anterior);
    }
    else if (final >= 7 && final <= 8.9)
    {
        printf("%s, %2f, %2f , desempenho bom", nome, final, nota_anterior);
    }
    else if (final >= 5 && final <= 6.9)
    {
        printf("%s, %2f, %2f , desempenho regular", nome, final, nota_anterior);
    }
    else if (final >= 0 && final <= 4.9)
    {
        printf("%s, %2f, %2f , desempenho insuficiente", nome, final, nota_anterior);
    }

    return 0;
}
