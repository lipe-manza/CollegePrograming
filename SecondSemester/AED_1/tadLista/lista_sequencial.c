#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista_s.h"  

#define TAMANHO_MAX 100

struct lista {
    ITEM* lista[TAMANHO_MAX];
    int inicio;
    int fim;
    int tamanho;
    bool ordenado;
};

LISTA* lista_criar(bool ordenado) {
    LISTA* list = (LISTA*)malloc(sizeof(LISTA));
    if (list != NULL) {
        list->inicio = 0;
        list->fim = 0;
        list->tamanho = 0;
        list->ordenado = ordenado;
    }
    return list;
}

bool lista_apagar(LISTA** list) {
    if (list != NULL && *list != NULL) {
        for (int i = 0; i < (*list)->tamanho; i++) {
            item_apagar(&((*list)->lista[i]));
        }
        free(*list);
        *list = NULL;
        return true;
    }
    return false;
}

int lista_busca_ordenada(LISTA* list, int chave) {
    if (list != NULL && list->tamanho > 0) {
        for (int i = 0; i < list->tamanho; i++) {
            if (chave < item_get_chave(list->lista[i])) {
                return i;  // posição onde deve ser inserido
            }
        }
        return list->tamanho; // insere no final
    }
    return 0;
}

bool lista_inserir_fim(LISTA* list, ITEM* item) {
    if (list != NULL && !lista_cheia(list)) {
        list->lista[list->fim] = item;
        list->fim++;
        list->tamanho++;
        return true;
    }
    return false;
}

bool lista_inserir_posicao(LISTA* list, int pos, ITEM* item) {
    if (list != NULL && !lista_cheia(list) && pos >= 0 && pos <= list->tamanho) {
        // desloca para a direita
        for (int i = list->tamanho; i > pos; i--) {
            list->lista[i] = list->lista[i - 1];
        }
        list->lista[pos] = item;
        list->tamanho++;
        list->fim++;
        return true;
    }
    return false;
}

bool lista_inserir(LISTA* list, ITEM* item) {
    if (!list->ordenado) {
        return lista_inserir_fim(list, item);
    }
    else {
        int x = lista_busca_ordenada(list, item_get_chave(item));
        return lista_inserir_posicao(list, x, item);
    }
}

bool lista_cheia(LISTA* lista) {
    if (lista != NULL) {
        return (lista->tamanho == TAMANHO_MAX);
    }
    return false;
}
