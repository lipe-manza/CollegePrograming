#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>
#include "item.h" // Supondo que você tenha a definição de ITEM em Item.h

typedef struct pilha PILHA;
typedef struct no NO;

// Criação e destruição
PILHA* pilha_criar();
void pilha_apagar(PILHA** pilha);

// Consultas
bool pilha_vazia(PILHA* pilha);
bool pilha_cheia(PILHA* pilha);
int pilha_tamanho(PILHA* pilha);
ITEM* pilha_topo(PILHA* pilha);

// Modificação
bool pilha_empilhar(PILHA* pilha, ITEM* item);
ITEM* pilha_desempilhar(PILHA* pilha);

#endif // PILHA_H