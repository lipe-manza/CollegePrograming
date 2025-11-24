#include "heap.h"

// left_child = 2*i+1
// right_child = 2*i + 2
// dad = (i - 1)/2

struct  sequencial_heap {
    ITEM* vector[TAM];
    int end;
    int start;
};

void heap_swap(SH* heap, int i, int j) {
    ITEM* tmp = heap->vector[i];
    heap->vector[i] = heap->vector[j];
    heap->vector[j] = tmp;
}

bool heap_insert(SH* heap, int key) {
    
}
void fix_up(SH* heap) {
    int  w = heap->end;
    int father = (w - 1) / 2;

    while (w > 0 && (item_get_key(heap->vector[w]) > heap_get_key(heap->vector[father]))) {
        swap(heap->vector[father]);
        w = father;
        father = (father - 1) / 2;
    }
}


void fix_down(F);
void heap_remove(F, x) {


}

void fix_down(SH* F) {
    int w = first(F);   // normalmente é 1 se a heap é 1-indexada
    while (has_child(F, w)) {
        int m = greater_child(F, w);  // filho maior
        // se o pai já é maior que o maior filho, a propriedade do heap está ok
        if (value(F, w) >= value(F, m)) {
            break;
        }
        // caso contrário, troca e continua descendo
        swap(F, w, m);
        w = m;
    }
}


