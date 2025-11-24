#include "circulo.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#ifndef PI
#define PI 3.14159265359
#endif


struct circulo_ {
    float raio;
    PONTO* center;
};

CIRCULO* circulo_criar(PONTO* w, float raio) {
    CIRCULO* circ = malloc(sizeof(CIRCULO));
    if (circ != NULL) {
        circ->center = w;
        circ->raio = raio;
    }
    return circ;
}

void circulo_apagar(CIRCULO* circ) {

    if (circ != NULL) {
        free(circ);
    }
}

float circulo_area(CIRCULO* circ) {
    return PI * circ->raio * circ->raio;
}

float distancia(CIRCULO* circ, PONTO* p) {

    float dx = pontoPegarX(circ->center) - pontoPegarX(p);
    float dy = pontoPegarY(circ->center) - pontoPegarY(p);

    return sqrt(dx * dx + dy * dy);
}