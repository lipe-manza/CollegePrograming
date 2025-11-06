#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha_s.h"

struct pilha {
    ITEM* item[TAM];
    int tamanho;
};

PILHA* pilha_criar() {
    PILHA* p = (PILHA*)malloc(sizeof(PILHA));
    if (p != NULL) p->tamanho = 0;
    return p;
}

bool pilha_vazia(PILHA* p) {
    return (p == NULL || p->tamanho == 0);
}

bool pilha_cheia(PILHA* p) {
    return (p != NULL && p->tamanho == TAM);
}

bool pilha_empilhar(PILHA* pilha, ITEM* item) {
    if (pilha != NULL && !pilha_cheia(pilha)) {
        pilha->item[pilha->tamanho] = item;
        pilha->tamanho++;
        return true;
    }
    return false;
}

ITEM* pilha_desempilhar(PILHA* p) {
    if (p != NULL && !pilha_vazia(p)) {
        p->tamanho--;
        return p->item[p->tamanho];
    }
    return NULL; // erro
}

ITEM* pilha_topo(PILHA* p) {
    if (p != NULL && !pilha_vazia(p)) {
        return p->item[p->tamanho - 1];
    }
    return NULL; // erro
}

void pilha_apagar(PILHA** p) {
    if (p != NULL && *p != NULL) {
        // libera todos os itens da pilha
        for (int i = 0; i < (*p)->tamanho; i++) {
            item_apagar(&((*p)->item[i]));
        }
        free(*p);
        *p = NULL;
    }
}
