#include <stdio.h>
int swap(int *a, int *b)
{
    int antes = *a;
    *a = *b;
    *b = antes;
}
int main()
{
    int ch1, ch2;
    scanf("%d %d", &ch1, &ch2);
    int *p1 = &ch1;
    int *p2 = &ch2;

    swap(p1, p2);
    printf("%d %d", *p1, *p2);
    return 0;
}