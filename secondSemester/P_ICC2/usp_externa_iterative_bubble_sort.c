/*
 Volta USP - Parte 2: Iterativo

 Enzo Trulenque Evangelista - 15819219
 Luiz Felipe Manzoli Franceschini - 16913300
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct no NO;
typedef struct lista LISTA;

struct no {
    char tamanho;
    NO* proximo;
};

struct lista {
    NO* inicio;
    NO* fim;
    int tamanho;
};

LISTA* lista_criar(void) {
    LISTA* lista = (LISTA*)malloc(sizeof(LISTA));
    if (lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return lista;
}
bool eh_usp(char* name) {
    bool usp;
    char count = 0;

    while (name[count] != '-') {
        count++;
    }
    return (name[count + 2] == 'u');
}

void formatar_nome(char* name) {
    char count = 0;

    while (name[count] != '-') {
        count++;
    }
    // Termina a string logo após o fim do nome
    name[count - 1] = '\0';

}



bool fila_vazia(LISTA* lista) {

    if (lista->tamanho == 0) {
        return true;
    }
    else {
        return false;
    }
}

NO fila_remover(LISTA* lista) {
    if (lista != NULL && !fila_vazia(lista)) {
        NO* p = lista->inicio;
        lista->inicio = p->proximo;
        lista->tamanho--;
        if (lista->tamanho == 0)
            lista->fim = NULL;
        NO aux = *p;
        free(p);
        return aux;
    }
    NO vazio = { 0 };
    return vazio;
}
bool lista_inserir(LISTA* lista, int tamanho) {
    if (lista != NULL) { // Corrigido o if
        NO* no = (NO*)malloc(sizeof(NO));
        if (no == NULL) return false; // Falha de malloc
        // Printf("%s\n", no->nome);
        no->tamanho = tamanho;
        no->proximo = NULL;
        if (lista->tamanho == 0) // se a lista está vazia, também é nó inicial
            lista->inicio = no;
        else {// Se a lista não está vazia , é o nó depois do ultimo nó inserido
            lista->fim->proximo = no;
        }
        lista->fim = no;
        lista->tamanho++;
        return true;
    }
    return false;
}


char tamanho_nome(char aux[])
{
    char ctr = 0;

    // Itera sobre os caracteres do buffer incrementando o contador se
    // o caractere for uma letra
    for (char i = 0; aux[i] != '\0'; i++) if (isalpha(aux[i])) ctr++;

    return ctr;
}

void printar_lista(LISTA* lista)
{
    printf("[");

    if (lista)
    {
        for (NO* no = lista->inicio; no; no = no->proximo)
        {
            printf("%d", no->tamanho);
            if (no->proximo) printf(", ");
        }
    }

    printf("]");
}

void preencher_vetor(LISTA* f, char vetor[]) {
    int i = 0;
    NO* p = f->inicio;
    while (p != NULL) {
        vetor[i++] = p->tamanho;
        p = p->proximo;
    }
}

void lista_atualizar(LISTA* f, char vetor[]) {
    int i = 0;
    NO* p = f->inicio;
    while (p != NULL) {
        p->tamanho = vetor[i++];
        p = p->proximo;
    }
}

void bubble_sorting(LISTA* f, int ops[]) {
    int n = f->tamanho;
    char arr[n];

    preencher_vetor(f, arr);// Preenche o vetor estático com os valores da lista

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - j - 1; i++) {
            ops[0]++; // comparação
            if (arr[i] > arr[i + 1]) {
                char tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                ops[1]++; // troca
            }
        }
    }

    lista_atualizar(f, arr); // Atualiza a lista com os valores de forma ordenada
}


int main() {

    LISTA* usp;
    LISTA* externa;
    usp = lista_criar();
    externa = lista_criar();

    char aux[300];
    int opsu[2] = { 0,0 };// Operações: comparação e troca para usp
    int opse[2] = { 0,0 };// Operações: comparação e troca para externo

    while (fgets(aux, sizeof(aux), stdin) != NULL) {
        if (eh_usp(aux)) {
            formatar_nome(aux);
            lista_inserir(usp, tamanho_nome(aux));
        }
        else {
            formatar_nome(aux);
            lista_inserir(externa, tamanho_nome(aux));
        }
    }

    bubble_sorting(usp, opsu);
    bubble_sorting(externa, opse);

    printf("USP - ");
    printar_lista(usp);
    printf("\nComparações: %d, Trocas: %d\n\n", opsu[0], opsu[1]);

    printf("Externa - ");
    printar_lista(externa);
    printf("\nComparações: %d, Trocas: %d\n", opse[0], opse[1]);

    free(usp);
    free(externa);

    return 0;
}