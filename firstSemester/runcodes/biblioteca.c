#include <stdio.h>
#include <stdlib.h>

int sw(int s, int **a, int **b, int **c, int **d)
{
    int *temp = *a;
    switch (s)
    {
    case -1:
        *a = NULL;
        break;
    case 0:
        **a += 1;
        break;
    case 1:
        if ((*a == NULL && *b != NULL) || (*a != NULL && *b == NULL) || (*a != NULL && b != NULL))
        {
            *a = *b;
            *b = temp;
        }
        break;
    case 2:
        if ((*a == NULL && *c != NULL) || (*a != NULL && *c == NULL) || (*a != NULL && c != NULL))
        {
            *a = *c;
            *c = temp;
        }
        break;
    case 3:
        if ((*a == NULL && *d != NULL) || (*a != NULL && *d == NULL) || (*a != NULL && d != NULL))
        {
            *a = *d;
            *d = temp;
        }
        break;
    }
}

int main()
{

    int l1, l2, l3, a1, a2, a3;
    char fora[] = "Livro fora da estante";
    scanf("%d %d %d", &l1, &l2, &l3);

    int *p1 = &l1;
    int *p2 = &l2;
    int *p3 = &l3;

    scanf("%d", &a1);
    sw(a1, &p1, NULL, &p2, &p3);
    scanf("%d", &a2);
    sw(a2, &p2, &p1, NULL, &p3);
    scanf("%d", &a3);
    sw(a3, &p3, &p1, &p2, NULL);

    if (p1 == NULL)
    {
        printf("cartao1 -> %s\ncartao2 -> %d\ncartao3 -> %d", fora, *p2, *p3);
    }
    else if (p2 == NULL)
    {
        printf("cartao1 -> %d\ncartao2 -> %s\ncartao3 -> %d", *p2, fora, *p3);
    }
    else if (p3 == NULL)
    {
        printf("cartao1 -> %d\ncartao2 -> %d\ncartao3 -> %s", *p1, *p2, fora);
    }

    return 0;
}