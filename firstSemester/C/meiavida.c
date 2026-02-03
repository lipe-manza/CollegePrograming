#include <stdio.h>

int main()
{
    float segundos, horas, minutos, massa, massa_incial;
    scanf("%f", &massa);
    massa_incial = massa;

    for (float i = 1, pow = 2; massa >= 0.5; i++, pow *= 2)
    {
        segundos += 50;
        massa = massa / pow;
    }

    minutos = segundos / 60;
    horas = segundos / 3600;

    printf("massa incial:%f\n massa final:%f\n horas:%f\n minutos:%f\n segundos:%f", massa_incial, massa, horas, minutos, segundos);

    return 0;
}
