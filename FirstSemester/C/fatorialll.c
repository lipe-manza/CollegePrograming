#include <stdio.h>

int main()
{

    int n;
int fatorial =1;
    printf("escreva um numero inteiro:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fatorial= fatorial * i;
    }

 printf("%d", fatorial);
}
