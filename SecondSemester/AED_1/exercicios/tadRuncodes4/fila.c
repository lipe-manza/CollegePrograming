#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

// Estrutura interna do nó da fila
typedef struct _no NO;

struct _no {
    ITEM* item; // ponteiro para o item armazenado
    NO* proximo; // próximo nó da fila
};

// Estrutura interna da fila
struct fila_ {
    NO* inicio; // primeiro elemento
    NO* fim;    // último elemento
    int tamanho; // número de elementos
};

// Cria uma fila vazia
FILA* fila_criar() {
    FILA* f = (FILA*)malloc(sizeof(FILA));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }
    return f;
}

// Insere um item no final da fila
bool fila_inserir(FILA* fila, ITEM* item) {
    if (fila != NULL && !fila_cheia(fila)) { // Corrigido o if
        NO* no = (NO*)malloc(sizeof(NO));
        if (!no) return false; // falha de malloc
        no->item = item;
        no->proximo = NULL;

        if (fila_vazia(fila)) // se a fila estava vazia
            fila->inicio = no;
        else
            fila->fim->proximo = no;

        fila->fim = no;
        fila->tamanho++;
        return true;
    }
    return false;
}

// Remove e retorna o item do início da fila
ITEM* fila_remover(FILA* fila) {
    if (fila != NULL && !fila_vazia(fila)) {
        NO* p = fila->inicio;
        ITEM* it = p->item;

        fila->inicio = p->proximo;
        fila->tamanho--;
        if (fila->tamanho == 0)
            fila->fim = NULL;

        free(p);
        return it;
    }
    return NULL; // fila vazia ou ponteiro nulo
}

// Retorna o item do início sem remover
ITEM* fila_frente(FILA* fila) {
    if (!fila_vazia(fila))
        return fila->inicio->item;
    return NULL;
}

// Retorna a quantidade de elementos da fila
int fila_tamanho(FILA* fila) {
    return fila->tamanho;
}

// Verifica se a fila está vazia
bool fila_vazia(FILA* fila) {
    return (fila->tamanho == 0);
}

// Verifica se a fila está cheia (lista encadeada nunca enche)
bool fila_cheia(FILA* fila) {
    return false;
}

// Apaga a fila e libera memória
void fila_apagar(FILA** fila) {
    if (fila && *fila) {
        while (!fila_vazia(*fila)) {
            ITEM* it = fila_remover(*fila);
            // Se necessário, liberar ITEM também
            // free(it);
        }
        free(*fila);
        *fila = NULL;
    }
}

// Função de depuração: imprime a fila (opcional)
void fila_imprimir(FILA* fila) {
    NO* p = fila->inicio;
    while (p != NULL) {
        // Exemplo: imprime o item como número, depende da definição de ITEM
        // printf("%d ", p->item->numero);
        p = p->proximo;
    }
    printf("\n");
}
