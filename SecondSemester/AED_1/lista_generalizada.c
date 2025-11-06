#include <stdio.h>
#include <stdbool.h>
#include "item.h"

typedef struct no_ NO;
typedef struct lista_ LISTA;

struct lista_ {
    NO* inicio;
    int profundidade;
};

struct no_ {
    int tipo;
    union {
        ITEM* atomo;
        struct no_* sublista;
    } info;
    NO* prox;
};

void lista_imprimir(NO* no) {
    if (no == NULL)return;

    if (no->tipo == 1) {
        lista_imprimir(no->info.sublista);
        lista_imprimir(no->prox);
    }
    else {
        printf(" %d", item_get_chave(no->info.atomo));
        lista_imprimir(no->prox);
    }
}

NO* lista_busca(NO* no, int chave) {
    if (no == NULL)return NULL;

    if (no->tipo == 1) {
        NO* aux;
        aux = lista_busca(no->info.sublista, chave);
        if (aux != NULL) return aux;
        else return    lista_busca(no->prox, chave);
    }
    else {
        return (item_get_chave(no->info.atomo) == chave) ? no : lista_busca(no->prox, chave);
    }

}

bool lista_comparar(NO* no1, NO* no2) {
    if ((no1 == NULL && no2 != NULL) || (no2 == NULL && no1 != NULL)) return false;

    if (no1 == NULL && no2 == NULL)return true;

    if (no1->tipo != no2->tipo)
        return false;
    else if (no1->tipo == 1) {
        return  (lista_comparar(no1->info.sublista, no2->info.sublista) && lista_comparar(no1->prox, no2->prox));
    }
    else return ((item_get_chave(no1->info.atomo) == item_get_chave(no2->info.atomo)) && lista_comparar(no1->prox, no2->prox));
}

bool lista_igual(LISTA* lista1, LISTA* lista2) {
    if (lista1->profundidade == lista2->profundidade) {
        return lista_comparar(lista1->inicio, lista2->inicio);
    }
    else {
        return 0;
    }
}


int lista_imprimir_iterativa(LISTA* lista) {
    if (lista != NULL) {
        NO* no = lista->inicio;
        while (no != NULL) {
            if (no->tipo == 1) {
                LISTA aux;
                aux.inicio=no->info.sublista;
                lista_imprimir(&aux);
            }
            else {
                printf(" %d", item_get_chave(no->info.atomo));
            }
            no = no->prox;
        }
        return 1;
    }
    return 0;
}
