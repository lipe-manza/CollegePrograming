#include <stdio.h>
int main()
{

    int resto = 0, n, count = 0;
    scanf("%d", &n);
    for (int i = n; i > 4; i--)
    {

        if (i % 5 == 0)
        {
            resto = i / 5;
            count++;

            while (resto % 5 == 0)
            {
                resto = resto / 5;
                count++;
            }
        }
    }

    printf("%d", count);
    return 0;
}