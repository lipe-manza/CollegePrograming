#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main(int argc, char *argv[]){
    
    LISTA *lista;
    ITEM *item;
    
    lista = lista_criar(false);
        
    lista_inserir (lista, item_criar(1));
    lista_inserir (lista, item_criar(12));    
    lista_inserir (lista, item_criar(18));
    lista_inserir (lista, item_criar(2));
    lista_inserir (lista, item_criar(8));

    item = lista_busca(lista, 8);
    if (item !=NULL)
    printf("\n==>%d",item_get_chave(item));
    else
        printf("\n ---> NULL!");



    item = lista_remover(lista, 12); // remove no do meio da lista
    item_apagar(&item); //apaga o item retornado. responsabilidade do chamado em vez de ser ser lista_remover(); decisão de projeto
    //lista_imprimir(lista);
    
    item = lista_remover(lista, 111); //remove 1o item da lista
    item_apagar(&item);
   // lista_imprimir(lista);

        
    lista_apagar(&lista);
    //lista_imprimir(lista);
   	
    return (0);
}


