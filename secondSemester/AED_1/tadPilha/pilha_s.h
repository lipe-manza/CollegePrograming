#ifndef PILHA_S_H
#define PILHA_S_H

#include <stdbool.h>
#include "item.h"

#define TAM 100

typedef struct pilha PILHA;

// cria pilha vazia
PILHA* pilha_criar();

// verifica se pilha está vazia
bool pilha_vazia(PILHA* p);

// verifica se pilha está cheia
bool pilha_cheia(PILHA* p);

// empilha elemento (push)
bool pilha_empilhar(PILHA* p, ITEM* item);

// desempilha elemento (pop)
ITEM* pilha_desempilhar(PILHA* p);

// consulta topo da pilha
ITEM* pilha_topo(PILHA* p);

// apaga pilha inteira
void pilha_apagar(PILHA** p);

#endif
