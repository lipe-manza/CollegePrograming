#include "Pilha.h"
#include <stdio.h>


bool balanceada(char* sequencia) {
    bool isVazia;//variável tipo bool para receber se a pilha ta vazia(true/false)
    PILHA* pilha = pilha_criar();//criando pilha 

    for (int i = 0; sequencia[i] != '\0'; i++) {//for que passa por todos os caracteres da String até o "\0"

        //verifica se são caracteres de abertura
        if ((sequencia[i] == '{') || (sequencia[i] == '(') || (sequencia[i] == '[')) {
            ITEM* caracter = item_criar(sequencia[i]);//cria um ITEM para empilhar
            pilha_empilhar(pilha, caracter);//empilha o ITEM na pilha
        }
        //verifica se a pilha ta vazia para não dar erro e verifica se os caracteres a serem lidos são complementos dos que tão no topo da pilha
        else if (!pilha_vazia(pilha) &&
            ((sequencia[i] == ')' && item_get_chave(pilha_topo(pilha)) == '(') ||
                (sequencia[i] == '}' && item_get_chave(pilha_topo(pilha)) == '{') ||
                (sequencia[i] == ']' && item_get_chave(pilha_topo(pilha)) == '['))) {
            ITEM* aux = pilha_desempilhar(pilha);//cria um ITEM auxiliar para desempilhar aqueles do topo
            item_apagar(&aux);//apaga o ITEM do topo
        }
        else {
            while (!pilha_vazia(pilha)) {//laço que esvazia a pilha enquanto ela não esta vazia  
                ITEM* aux = pilha_desempilhar(pilha);//ITEM auxiliar para desempilhar
                item_apagar(&aux);//apaga os ITEMS
            }
            pilha_apagar(&pilha);//apaga a pilha
            return false;
        }
    }

    isVazia = pilha_vazia(pilha);//verifica se a pilha ta vazia, pois se tiver significa que a sequencia era balanceada ja que cada caracter de abertura tinha o seu de fechamento

    if (!isVazia) {//caso a pilha não tenha sido esvaziada, desempilha e esvazia a pilha apagando os ITEMS
        while (!pilha_vazia(pilha)) {
            ITEM* aux = pilha_desempilhar(pilha);
            item_apagar(&aux);
        }
    }

    pilha_apagar(&pilha);// apaga a pilha 


    return isVazia; //retorna se ela ta vazia ou não, ou seja, se a sequencia é balanceada ou não

}


