#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.c"

typedef struct no NO;
typedef struct no {
    ITEM* item;
    NO* proximo;
};

typedef struct lista {
    NO* sentinela;
    int tamanho;
} LISTA;

// Função para criar a lista
LISTA* lista_criar() {
    // aloca a lista
    LISTA* lista = (LISTA*)malloc(sizeof(LISTA));
    if (lista != NULL) {
        // cria o nó sentinela
        NO* sent = (NO*)malloc(sizeof(NO));
        if (sent == NULL) {
            free(lista);
            return NULL;
        }

        sent->item = NULL;      // sentinela não guarda item
        sent->proximo = sent;   // aponta para si mesma (circular)
        lista->sentinela = sent;
        lista->tamanho = 0;
    }
    return lista;
}

bool inserir_ordenado(LISTA* lista, ITEM* item) {
    if (lista != NULL && !(lista_cheiar(lista))) {
        NO* no = (NO*)malloc(sizeof(NO));
        if (no != NULL) {
            no->item = item;
            NO* p = lista->sentinela->proximo;
            NO* a = lista->sentinela;

            while (p != lista->sentinela && item_get_chave(item) > item_get_chave(p->item)) {
                a = p;
                p = p->proximo;
            }
            a->proximo = no;
            no->proximo = p;
            lista->tamanho++;
            return true;
        }
    }
    return false;

}


ITEM* lista_remover(LISTA* lista, ITEM* item) {
    if (lista != NULL && !(lista_vazia(lista))) {
        NO* p = lista->sentinela->proximo;
        NO* a = lista->sentinela;
        while (p != lista->sentinela && item_get_chave(item) != item_get_chave(p->item)) {
            a = p;
            p = p->proximo;
        }
        ITEM* aux = p->item;
        a->proximo = p->proximo;
        p->proximo = NULL;
        lista->tamanho--;
        free(p);
        p = NULL;
        return aux;
    }
    return NULL;
}

ITEM* busca(LISTA* lista, int  chave) {
    if (lista != NULL && !(lista_vazia(lista))) {
        item_set_chave(lista->sentinela->item, chave);
        NO* p= lista->sentinela->proximo;

        while (item_get_chave(p->item) < chave) {
            p = p->proximo;
        }
        ITEM* item = p->item;
        return (p != lista->sentinela && item_get_chave(p->item)==chave) ? item : NULL;

    }
    return NULL;

}


