// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include "fila.h"


// //funcao remover os nos um por um recursivamente
// void nos_remover(NO* n) {
//     if (n == NULL) {
//         return;
//     }
//     nos_remover(n->proximo);   // remove o resto da lista
//     item_apagar(&(n->item));   // apaga o item
//     free(n);
//     n = NULL;               // libera o nó
// }

// // Função para apagar recursivamente a fila removendo e apagando cada item
// void fila_apagar(FILA** f) {
//     if (f != NULL && *f != NULL) {
//         nos_remover((*f)->inicio);
//         (*f)->tamanho = 0;   // fila agora está vazia
//         free(*f);
//         *f = NULL;
//     }
// }




