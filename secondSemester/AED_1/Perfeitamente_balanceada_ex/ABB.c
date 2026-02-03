#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "abb.h"

typedef struct no NO;

struct no {
    ITEM* item;
    NO* esq;
    NO* dir;
};

struct abb {
    NO* raiz;
    int profundidade;
};

ABB* abb_criar(void) {
    ABB* a = (ABB*)malloc(sizeof(ABB));
    if (a) {
        a->raiz = NULL;
        a->profundidade = -1;
    }
    return a;
}

NO* abb_criar_no(ITEM* item) {
    NO* novo_no = (NO*)malloc(sizeof(NO));
    if (novo_no != NULL) {
        novo_no->dir = NULL;
        novo_no->esq = NULL;
        novo_no->item = item;
    }
    return novo_no;
}

NO* abb_inserir_no(NO* raiz, NO* novo_no) {
    if (raiz == NULL) {
        return novo_no;
    }

    if (item_get_chave(novo_no->item) < item_get_chave(raiz->item)) {
        raiz->esq = abb_inserir_no(raiz->esq, novo_no);
    }
    else if (item_get_chave(novo_no->item) > item_get_chave(raiz->item)) {
        raiz->dir = abb_inserir_no(raiz->dir, novo_no);
    }

    return raiz;
}

bool abb_inserir(ABB* T, ITEM* item) {
    if (T == NULL) return false;
    NO* novo_no = abb_criar_no(item);
    if (novo_no != NULL) {
        T->raiz = abb_inserir_no(T->raiz, novo_no);
        return true;
    }
    return false;
}

int abb_altura(NO* raiz) {
    if (raiz == NULL) return -1;

    int ae = abb_altura(raiz->esq);
    int ad = abb_altura(raiz->dir);

    return ((ae > ad) ? ae : ad) + 1;
}

bool abb_perf_balan(NO* raiz) {
    if (raiz == NULL) return true;

    int left = abb_altura(raiz->esq);
    int right = abb_altura(raiz->dir);

    if (left != right) return false;

    return abb_perf_balan(raiz->esq) && abb_perf_balan(raiz->dir);
}

// wrapper
bool abb_perfeitamente_balanceada(ABB* T) {
    if (T != NULL) {
        return abb_perf_balan(T->raiz);
    }
    return false;
}
    