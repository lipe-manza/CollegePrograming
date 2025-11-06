#include "pilha_e.h"
#include <stdio.h>
#include <stdlib.h>

struct no {
    ITEM* item;
    NO* anterior;

};
struct pilha {
    NO* topo;
    int tamanho;
};

//Create and Erase
PILHA* pilha_criar() {
    PILHA* pilha = (PILHA*)malloc(sizeof(PILHA));
    if (pilha != NULL) {
        pilha->topo = NULL;//se usar calloc nao precisaria fazer isso
        pilha->tamanho = 0;
    }
    return pilha;
}

void pilha_apagar(PILHA** pilha) {
    NO* p;
    if (pilha != NULL && *(pilha) != NULL && !(pilha_vazia(pilha))) {
        while ((*pilha)->topo != NULL)
        {
            p = (*pilha)->topo;
            (*pilha)->topo = (*pilha)->topo->anterior;
            item_apagar(&(p->item));
            p->anterior = NULL;
            free(p);
            p = NULL;
            (*pilha)->tamanho--;
        }
    }
    free(*pilha);
    (*pilha) = NULL;
}


//Stacking and Popping

bool pilha_empilhar(PILHA* pilha, ITEM* item) {
    if (!(pilha_cheia(pilha))) {
        NO* p = (NO*)malloc(sizeof(NO));
        if (p != NULL) {
            p->anterior = pilha->topo;
            pilha->topo = p;
            p->item = item;
            pilha->tamanho++;
            return true;
        }
    }
    return false;
}


ITEM* pilha_desemplihar(PILHA* pilha) {
    if (!(pilha_vazia(pilha)) && pilha != NULL) {
        NO* p;
        ITEM* item;
        p = pilha->topo;
        pilha->topo = p->anterior;
        item = p->item;
        p->anterior = NULL;
        free(p);
        p = NULL;
        pilha->tamanho--;
        return item;
    }
}

ITEM* fila_remover(PILHA* pilha) {
    if (pilha != NULL && !(pilha_vazia(pilha))) {
        PILHA* aux = pilha_criar();

        NO* p;
        ITEM* it;

        while (!pilha_vazia(pilha)) {
            pilha_empilhar(aux, pilha_desempilhar(pilha));
        };

        it = pilha_desempilhar(aux);

        while (!pilha_vazia(aux)) {
            pilha_empilhar(pilha, pilha_desempilhar(aux));
        };

        pilha_apagar(&aux);
        return it;
    }
    return NULL;
}


void pilha_inverter(PILHA* pilha) {
    if (pilha != NULL && !(pilha_vazia(pilha))) {
        NO* anterior = NULL;
        NO* atual = pilha->topo;
        NO* proximo = pilha->topo->anterior;
        while (atual != NULL) {
            proximo = atual->anterior;
            atual->anterior = anterior;
            anterior = atual;
            atual = proximo;
        }
        pilha->topo = anterior;
    }
}