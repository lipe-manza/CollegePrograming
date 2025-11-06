#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int pa(int q, int a1)
{
    int pan;
    if (q == 1)
    {
        return a1 + 1;
    }
    if (q % 2 == 0)
    {
        pan = a1 - ((int)pow(2, (q - 1)));
        return pan;
    }
    else
    {
        pan = a1 + ((int)pow(2, (q - 1)));
        return pan;
    }
}

int main()
{

    int a, b, total = 0, i = 1;
    scanf("%d %d", &a, &b);
    int anterior = a, final = a;
    if (a == b)
    {
        printf("0");
    }
    if (a > b)
    {

        while (final > b)
        {

            final = pa(i, a);
            total += abs(final - anterior);
            i++;
            anterior = final;
        }

        printf("%d", total - abs(final - b));
    }
    if (a < b)
    {

        while (final < b)
        {

            final = pa(i, a);
            total += abs(final - anterior);
            i++;
            anterior = final;
        }
        printf("%d", total - abs(final - b));
    }
}
