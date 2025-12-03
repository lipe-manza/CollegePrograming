#include "heap.h"

// left_child = 2*i+1
// right_child = 2*i + 2
// parent = (i - 1)/2

struct  sequencial_heap {
    ITEM* vector[TAM];
    int end;
};

SH* hep_criar() {
    SH* heap = (SH*)malloc(TAM * sizeof(SH));
    if (heap != NULL) {
        heap->end = -1;
    }
    return heap;
}
int heap_cheia(SH* heap) {
    return (heap->end == TAM - 1);
}

int heap_vazia(SH* heap) {
    return (heap->end == -1);
}

void swap(SH* heap, int i, int j) {
    ITEM* tmp = heap->vector[i];
    heap->vector[i] = heap->vector[j];
    heap->vector[j] = tmp;
}

void fix_up(SH* heap) {
    int  w = heap->end;
    int parent = (w - 1) / 2;

    while (w > 0 && (item_get_key(heap->vector[w]) > heap_get_key(heap->vector[parent]))) {
        swap(heap, w, parent);
        w = parent;
        parent = (w - 1) / 2;
    }
}

bool heap_insert(SH* heap, ITEM* item) {
    if (heap == NULL) return false;

    if (heap_cheia(heap)) return false;

    heap->end++;
    heap->vector[heap->end] = item;

    fix_up(heap);

    return true;

}



void fix_down(SH* heap) {
    int w = 0;
    int max_child;
    // Continua enquanto o nó atual 'w' tiver pelo menos um filho à esquerda (2*w + 1)
    // O índice do filho esquerdo deve estar dentro dos limites da heap (<= heap->end).
    while ((2 * w + 1) <= heap->end) {
        int left_child = 2 * w + 1;
        int right_child = 2 * w + 2;
        // Encontra o índice do maior filho (max_child)
        // Assume que o filho esquerdo é o maior inicialmente
        max_child = left_child;
        // Verifica se o filho direito existe (right_child <= heap->end) E se ele é maior que o esquerdo
        if (right_child <= heap->end &&
            item_get_key(heap->vector[right_child]) > item_get_key(heap->vector[left_child])) {
            max_child = right_child;
        }
        // Compara o pai (w) com o maior filho (max_child)
        // Se a propriedade de Max Heap (pai >= filho) já for verdadeira, para.
        if (item_get_key(heap->vector[w]) >= item_get_key(heap->vector[max_child])) {
            break;
        }
        // Caso contrário, troca e continua descendo
        swap(heap, w, max_child);
        w = max_child; // Move para a posição do filho trocado
    }
}

ITEM* heap_remove(SH* heap) {
    //  Verifica se a Heap existe ou está vazia
    if (heap == NULL || heap_vazia(heap)) {
        return NULL; // Retorna NULL se a heap estiver vazia ou não existir
    }

    ITEM* removed_item = heap->vector[0];
    //Substitui a raiz (índice 0) pelo último elemento
    heap->vector[0] = heap->vector[heap->end];
    //Decrementa o índice 'end' para remover o último elemento da heap
    heap->end--;
    // Restaura a propriedade da Heap chamando fix_down no novo elemento raiz (índice 0)
    // Chamamos fix_down apenas se a heap ainda tiver elementos
    if (!heap_vazia(heap))
        fix_down(heap);
    // Retorna o item que foi removido
    return removed_item;
}





