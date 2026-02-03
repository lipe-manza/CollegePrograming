#include <stdio.h>

int main()
{
    int letters = 0, numbers = 0;
    char total[100];

    scanf("%s", total);
    for (int i = 0; total[i] != '\0'; i++)
    {
        if (total[i] >= 'a' && total[i] <= 'z')
        {
            letters++;
        }
        if (total[i] >= '0' && total[i] <= '9')
        {
            numbers++;
        }
    }
    printf("quantidade de numeros:%d\n quantidade de letras:%d", numbers, letters);

    return 0;
}