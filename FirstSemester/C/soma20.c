#include <stdio.h>
int power(int a, float b)
{
    float sq = 1;
    for (int j = 0; j < a + 1; j++)
    {
        sq = sq * b;
    }
    return sq;
}
int fat(int c)
{
    int ft = 1;
    for (int w = c; w > 1; w--)
    {
        ft *= w;
    }
    return ft;
}

int main()
{
    float x;
    printf("escreva um numero:");
    scanf("%f", &x);
    float s = x;
    int i, count = 0;

    for (i = 1; i < 39; i = i + 2)
    {

        count++;
        float term = (float)power(i, x) / fat(i + 2);
        if (count % 2 == 1)
        {
            s += -term;
        }
        else
        {
            s += term;
        }
    }
    printf("%.10f", s);

    return 0;
}

// tinha como fazer sem usar funções apenas colocando as funcões como for dentro do for, alem disso o sinal pose ser alternado usando o for e um "int sinal=-1" com "sinal*=-1" o que faz alternar o sinal