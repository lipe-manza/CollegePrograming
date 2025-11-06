#ifndef CIRCULO_H
#define CIRCULO_H

#include "ponto.h"

typedef struct circulo_ CIRCULO;
CIRCULO *circulo_criar(PONTO *w, float raio);
void circulo_apagar(CIRCULO *circ);
float circulo_area(CIRCULO *circ);
float distancia(CIRCULO *circ, PONTO* w);//foi necessario a inclusao dessa nova funcao para poder calcular a distancia entre um ponto e o centro da circunferencia

/*
Pode ser necessário definir outras operações para o TAD.
Se for o caso, faça e justifique!
*/
#endif
