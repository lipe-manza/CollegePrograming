#include <stdio.h>
int main()
{
    int n;

    printf("escreva a quantidade de numeros:");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("escreva o %d numero:", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) // faz repetir o for interior, isto é faz com que o for percorra o arr mais de uma vez

    {

        for (int j = 0; j < n - 1 - i; j++) //em n-1-i o "i" delimita até onde o bubble sort ira ir, visto que após a primeira ida(0) o primeiro termo já irá estar no ultimo lugar, não precisando comparalo de novo
        {
            if (arr[j] < arr[j+ 1])
            {

                int a0 = arr[j];     // armazenamos o termo da esquerda em "ao"
                arr[j] = arr[j + 1]; // o termo da esquerda vira o da direita
                arr[j + 1] = a0;     // o termo da direita recebe o valor do da esquerda
            }
        }
    }

    for (int t = 0; t < n; t++)
    {
        printf(" %d ", arr[t]);
    }
    return 0;
}
