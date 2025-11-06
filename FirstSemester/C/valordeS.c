#include <stdio.h>
#include <math.h>

int main()
{
    float s = 1, denominador = 1, numerador = 1;
    for (float i = 0; i < 49; i++)
    {
        numerador += (2);
        denominador += 1;
        s += numerador / denominador;
    }
    printf("%f", s);
    return 0;
}
