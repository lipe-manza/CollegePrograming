#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

typedef struct no NO;

struct no {
    ITEM* item;
    NO* anterior;
    NO* proximo;
};

struct lista {
    NO* inicio;
    NO* fim;
    int tamanho;
    bool ordenado;
};

ITEM* lista_remover(LISTA* lista, int chave) {
    NO* p;
    if (lista != NULL && !lista_vazia(lista)) {
        p = lista->inicio;
        while (p != NULL && item_get_chave(p->item) != chave) {
            p = p->proximo;
        }
        if (p != NULL) {
            if (p == lista->inicio) {
                lista->inicio = p->proximo;
            }
            else {
                p->anterior->proximo = p->proximo;
            }
            if (p == lista->fim) {
                lista->fim = p->anterior;
            }
            else {
                p->proximo->anterior = p->anterior;
                ITEM* aux;
                aux = p->item;
                free(p);
                p = NULL;
                return aux;
            }
        }
    }
}

bool lista_vazia(LISTA* lista) {
    ;
}

bool inserir_ordenado(LISTA* lista, ITEM* item) {
    if (lista != NULL && !(lista_cheia(lista))) {
        NO* p = lista->inicio;
        NO* no = (NO*)malloc(sizeof(NO));
        if (no == NULL) return false; // segurança
        no->item = item;
        if (p == NULL) {
            lista->inicio = no;
            lista->fim = no;
            no->anterior = NULL;
            no->proximo = NULL;
            lista->tamanho++;
            return true;
        }
        while (p != NULL && item_get_chave(item) > item_get_chave(p->item)) {
            p = p->proximo;
        }
        if (p != NULL) {
            if (p == lista->inicio) {
                lista->inicio = no;
            }
            else {
                p->anterior->proximo = no;
            }
            no->proximo = p;
            no->anterior = p->anterior;
            p->anterior = no;
            lista->tamanho++;
            return true;
        }
        else {
            no->anterior = lista->fim;
            no->proximo = NULL;
            lista->fim->proximo = no;
            lista->fim = no;
            lista->tamanho++;
            return true;
        }
    }
    return false;

}

