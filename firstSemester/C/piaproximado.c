#include <stdio.h>
#include <math.h>

int main()
{
    double s = 0, den = 1, pi;
    double sinal = 1;
    for (int i = 0; i < 1000; i++)
    {
        s += (1 / (den * den * den)) * sinal;
        den += 2;
        sinal *= -1;
    }
    pi = pow((32 * s), (1.0 / 3.0));

    printf("%f", pi);
    return 0;
}