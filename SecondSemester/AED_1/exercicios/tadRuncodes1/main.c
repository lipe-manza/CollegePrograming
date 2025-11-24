#include <stdio.h>
#include "circulo.h"


int main() {

    float radius, distance, xp, yp, xw, yw;

    // Lendo o ponto
    scanf("%f %f", &xp, &yp);

    // Lendo o centro do círculo e o raio
    scanf("%f %f %f", &xw, &yw, &radius);

    PONTO* p = ponto_criar(xp, yp);
    PONTO* w = ponto_criar(xw, yw);

    CIRCULO* circum = circulo_criar(w, radius);

    distance = distancia(circum, p);

    if (distance == radius) {

        printf("O ponto pertence à circunferência.\nDistância: %.2f\n", distance);
    }
    else if (distance > radius) {

        printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", distance);
    }
    else {

        printf("O ponto é interior à circunferência.\nDistância: %.2f\n", distance);
    }

    ponto_apagar(p);
    ponto_apagar(w);
    circulo_apagar(circum);

    return 0;



}