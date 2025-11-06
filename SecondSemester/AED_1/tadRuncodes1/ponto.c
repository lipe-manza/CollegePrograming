#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

struct ponto_ {
    float x;
    float y;
};

PONTO* ponto_criar(float x, float y) {

    PONTO* p = malloc(sizeof(PONTO));

    p->x = x;
    p->y = y;

    return p;
}
void ponto_apagar(PONTO* p) {
    if (p != NULL) {
        free(p);
    }
}


bool ponto_set(PONTO* p, float x, float y) {
    if (p != NULL) {
        p->x = x;
        p->y = y;
        return true;
    }
    else {
        return false;
    }
}

float pontoPegarX(PONTO* p) {

    return p->x;
}
float pontoPegarY(PONTO* p) {

    return p->y;
}
