#include <stdio.h>
#include <math.h>

int main()
{

    float a, b, c, x1, x2, delta;

    printf("escreva o valor de a: ");
    scanf("%f", &a);
    printf("escreva o valor de b: ");
    scanf("%f", &b);
    printf("escreva o valor de c: ");
    scanf("%f ", &c);

    delta = b * b - (4 * a * c);

    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);

    printf("x1: %f\n", x1);
    printf("x2: %f,", x2);

    return 0;
}