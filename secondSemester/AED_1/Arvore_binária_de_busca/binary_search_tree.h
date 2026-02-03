#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "item.h"
#include <stdbool.h>

// Estrutura do nó da árvore binária de busca
typedef struct node ND;
// Estrutura principal da árvore binária de busca
typedef struct binary_search_tree BST;

// Cria uma árvore binária de busca vazia
BST *bst_create(void);
// Insere um novo ITEM na árvore
bool bst_insert(BST *T, ITEM *item);
// Percurso em pré-ordem: Raiz -> Esquerda -> Direita
void bst_preorder(ND *root);
// Percurso em ordem: Esquerda -> Raiz -> Direita
void bst_inorder(ND *root);
// Percurso em pós-ordem: Esquerda -> Direita -> Raiz
void bst_postorder(ND *root);
// Calcula a profundidade (altura) da árvore
int BT_depth(ND *r);

#endif
