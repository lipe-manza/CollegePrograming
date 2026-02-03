#include <stdio.h>

int main()
{
    int x, log = 1, count = 0;
    scanf("%d", &x);

    if (x == 10)
    {
        printf("log2 x=0");
    }
    else
    {
        while (log != x)
        {
            count += 1;
            log *= 2;
        }
    }
    printf("%d", count);

    return 0;
}