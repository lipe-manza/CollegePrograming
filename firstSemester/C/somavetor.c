#include <stdio.h>

int main()
{

    int vector[10], soma;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vector[i]);
    }

    for (int j = 0; j < 10; j++)
    {
        soma += vector[j];
    }

    printf("%d", soma);

    return 0;
}