#include <stdio.h>

typedef struct no {
    int chave;
    char valor[10];
} NO;

// **Values swap
// void swap(NO* n1, NO* n2) {
//     NO aux = *n2;
// /    *n2 = *n1;
// /    *n1 = aux;
// }


// int main() {
//     NO no1 = { 1, "aaa" };
//     NO no2 = { 2, "bbb" };

//     swap(&no1, &no2);

//     printf("no1: %d , %s\n", no1.chave, no1.valor);
//     printf("no2: %d , %s\n", no2.chave, no2.valor);

//     return 0;
// }



// **Adress swap
void swap(NO** n1, NO** n2) {
    NO* aux = *n2;
    *n2 = *n1;
    *n1 = aux;
}

int main() {

    NO no1 = { 1, "aaa" };
    NO no2 = { 2, "bbb" };

    NO* np1 = &no1;
    NO* np2 = &no2;


    swap(&np1, &np2);

    printf("no1: %d , %s\n", np1->chave, np1->valor);
    printf("np2: %d , %s\n", np2->chave, np2->valor);

}