#ifndef PONTO_H
#define PONTO_H
#include <stdbool.h>

typedef struct ponto_ PONTO;
PONTO* ponto_criar(float x, float y);
void ponto_apagar(PONTO* p);
bool ponto_set(PONTO* p, float x, float y);
float pontoPegarX(PONTO* p);
float pontoPegarY(PONTO* p);
// foi necessario definir essas duas novss funções "pontoPegar" para que fosse possivel pegar os valores(float) do x e y de um ponto p(no caso do centro do circulo)


/*
Pode ser necessário definir outras operações para o TAD.
Se for o caso, faça e justifique!
*/
#endif





