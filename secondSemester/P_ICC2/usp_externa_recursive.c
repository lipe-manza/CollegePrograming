//  Enzo Trulenque Evangelista - 15819219
//  Luiz Felipe Manzoli Franceschini - 16913300
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef struct no NO;
typedef struct fila FILA;

struct no {
    char nome[100];
    int tamanho;
    NO* proximo;
};

struct fila {
    NO* inicio;
    NO* fim;
    int tamanho;
};

FILA* filaCriar(void) {
    FILA* fila = (FILA*)malloc(sizeof(FILA));
    if (fila) {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->tamanho = 0;
    }
    return fila;
}
bool isUsp(char* name) {
    bool usp;
    int count = 0;

    while (name[count] != '-') {
        count++;
    }
    return (name[count + 2] == 'u');
}

void formatName(char* name) {
    int count = 0;

    while (name[count] != '-') {
        count++;
    }
    name[count - 1] = '\0';

}



bool filaVazia(FILA* fila) {

    if (fila->tamanho == 0) {
        return true;
    }
    else {
        return false;
    }
}

NO filaRemover(FILA* fila) {
    if (fila != NULL && !filaVazia(fila)) {
        NO* p = fila->inicio;
        int tam = p->tamanho;

        fila->inicio = p->proximo;
        fila->tamanho--;
        if (fila->tamanho == 0)
            fila->fim = NULL;

        NO aux = *p;
        free(p);
        return aux;
    }
    NO vazio = { 0 };
    return vazio;
}
bool filaInserir(FILA* fila, char* nome, int tamanho) {
    if (fila != NULL) { // Corrigido o if
        NO* no = (NO*)malloc(sizeof(NO));
        if (no == NULL) return false; // falha de malloc
        strcpy(no->nome, nome);
        // printf("%s\n", no->nome);
        no->tamanho = tamanho;
        no->proximo = NULL;

        if (fila->tamanho == 0) // se a fila estava vazia
            fila->inicio = no;
        else {
            fila->fim->proximo = no;
        }
        fila->fim = no;
        // printf("%d\n", fila->tamanho);
        fila->tamanho++;
        // printf("%d\n", fila->tamanho);

        return true;
    }
    return false;
}

int nameSize(char* name) {
    if (name[0] == '\0') {
        return 0;
    }
    if (isalpha(name[0])) {
        return 1 + nameSize(name + 1);
    }
    else {
        return 0 + nameSize(name + 1);
    }
}

void printFila(FILA* fila) {
    NO aux;
    printf("[");
    while (!filaVazia(fila)) {
        aux = filaRemover(fila);
        printf("%d", aux.tamanho);
        if (!filaVazia(fila)) {
            printf(", ");
        }
    }
    printf("]");

}

int main() {

    FILA* usp;
    FILA* externa;
    usp = filaCriar();
    externa = filaCriar();

    char aux[100];

    while (fgets(aux, sizeof(aux), stdin) != NULL) {
        if (isUsp(aux)) {
            formatName(aux);
            filaInserir(usp, aux, nameSize(aux));
        }
        else {
            formatName(aux);
            filaInserir(externa, aux, nameSize(aux));
        }
    }

    printf("USP - ");
    printFila(usp);
    printf("\n");
    printf("Externa - ");
    printFila(externa);

    free(usp);
    free(externa);

    return 0;
}