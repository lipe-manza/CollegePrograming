#include <stdio.h>

int main()
{

    float n1, n2, sum, multi, div, sub;
    char o;

    scanf("%f %c %f", &n1, &o, &n2);

    switch (o)
    {
    case '+':
        sum = n1 + n2;
        printf("%.2f", sum);
        break;
        case '*':
        multi = n1 * n2;
        printf("%.2f", multi);
        break;
        case '/':
        div = n1 / n2;
        printf("%.2f", div);
        break;
        case '-':
        sub=n1-n2;
        printf("%.2f", sub);
        break;
    }
    
    return 0;
}