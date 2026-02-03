#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lista.h"  

typedef struct no {
    ITEM* item;
    NO* proximo;
}NO;

struct lista {
    NO* inicio; //! pode usar o cabeça apontando para o inicio da lista para a lista nao ter o no inicio
    NO* fim;
    int tamanho;
    bool ordenado;
};

LISTA* lista_criar(bool ordenada) {
    LISTA* list = (LISTA*)malloc(sizeof(LISTA));
    if (list) {
        list->inicio = NULL;
        list->fim = NULL;
        list->tamanho = 0;
        list->ordenado = ordenada;
    }
    return list;
}
bool lista_inserir(LISTA* list, ITEM* item) {
    bool x = false;
    if (list != NULL && !lista_cheia(list)) {
        if (!list->ordenado) {
            ;
        }
        else {
            x = lista_inserir_fim(list, item);
            return x;
        }
    }
}

bool lista_inserir_fim(LISTA* list, ITEM* item) {
    NO* p = (NO*)malloc(sizeof(NO));
    if (p) {
        p->item = item;
        p->proximo = NULL;
        if (list->tamanho == 0) {
            list->inicio = p;
        }
        else {
            list->fim->proximo = p;
        }
        list->tamanho++;
        list->fim = p;
        return true;
    }
    return false;
}

ITEM* lista_remover(LISTA* lista, int chave) {
    NO* a;
    NO* p;
    ITEM* item;

    if (lista && !lista_vazia(lista)) {
        p = lista->inicio;
        while (p != NULL && item_get_chave(p->item) != chave) {
            a = p;
            p = p->proximo;
        }
        if (p != NULL) {
            if (p == lista->inicio) {
                lista->inicio = p->proximo;
            }
            else {
                a->proximo = p->proximo;
            }
            if (p == lista->fim) {
                lista->fim = a;
            }
            item = p->item;
            p->proximo = NULL;
            free(p);
            lista->tamanho--;
            return item;
        }
    }
    return NULL;
}

bool lista_apagar(LISTA** lista);

ITEM* lista_busca_n_ordenada(LISTA* lista, int chave) {
    NO* p;
    if (lista != NULL) {
        p = lista->inicio;
        while (p != NULL) {
            if (item_get_chave(p->item) == chave) {
                return p->item;
            }
            else {
                p = p->proximo;
            }
        }
        return NULL;
    }
    return NULL;
}

ITEM* lista_busca_ordenada(LISTA* lista, int chave) {
    NO* p;
    if (lista != NULL) {
        p = lista->inicio;
        while (p != NULL && item_get_chave(p->item) < chave) {
            p = p->proximo;
        }
        if (p == NULL || item_get_chave(p->item) > chave) {
            return NULL;
        }
        else {
            return p->item;
        }
    }
    return NULL;
}

ITEM* lista_busca_rec(NO* n, int chave) {
    if (n == NULL) {
        return NULL;
    }
    if (item_get_chave(n->item) == chave) {
        return n->item;
    }
    else {
        return lista_busca_rec(n->proximo, chave);
    }

}

ITEM* lista_busca(LISTA* lista, int chave) {
    ITEM* item;
    if (lista != NULL) {
        if (lista->ordenado) {
            item = lista_busca_ordenada(lista, chave);
        }
        else {
            item = lista_busca_n_ordenada(lista, chave);
        }
        return item;
    }
    return NULL;
}

int lista_tamanho(LISTA* lista) {
    if (lista != NULL) {
        return lista->tamanho;
    }
    return 0;
}

bool lista_vazia(LISTA* lista) {
    if (lista != NULL) {
        if (lista->tamanho == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}
bool lista_cheia(LISTA* lista);
void lista_imprimir(LISTA* lista);



/*Fun��es adicionais*/
int lista_inverter(LISTA** lista);
bool lista_comparar(LISTA* l1, LISTA* l2);