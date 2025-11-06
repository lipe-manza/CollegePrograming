#include <stdio.h>

float potencia(float base, int exp)
{
    int i;
    int res = 1;

    for (i = 0; i < exp; i++)
    {
        res *= base;
    }

    return res;
}
int fatorial(int n)
{
    int i, res=1;

    for (i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
int main()
{
    int x = 0, n = 0, expo = 0, fat = 1;
    float res = 1;
    printf("escreva x:");

    scanf(" %d", &x);
    printf("escreva n:");

    scanf(" %d", &n);
    int sinal = -1;

    for (int i = 1; i < n; i++) // percorre até n termos
    {
        expo += 2;
        fat += 2;
        res += sinal * (potencia(x, expo) / fatorial(fat));
        sinal *= -1; // inverte o sinal
    }

    printf("resultado: %0.2f", res);
    return 0;
}