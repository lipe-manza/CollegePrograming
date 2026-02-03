#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main (void){
    FILA *fila=NULL;

    int i;
    ITEM *it;

    fila = fila_criar();

    i = 0;
    while(i<=9){
       fila_inserir(fila, item_criar(i));
       i++;
    }

    fila_imprimir(fila);

    it = fila_remover(fila);
    item_apagar(&it);

    it = fila_remover(fila);
    item_imprimir(it);
    item_apagar(&it);
    
    fila_imprimir(fila);
    
    
    fila_inserir(fila, item_criar(1001));
    
    fila_imprimir(fila);

    fila_inserir(fila, item_criar(10));
    
    fila_imprimir(fila);
    
    
    //fila_apagar(&fila);

    return(0);
}
