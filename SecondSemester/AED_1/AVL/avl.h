#ifndef BINARY_BALANCED_SEARCH_TREE_H
#define BINARY_BALANCED_SEARCH_TREE_H

#include "item.h"
#include <stdbool.h>

typedef struct node ND;
// Estrutura principal da árvore binária de busca
typedef struct binary_balanced_search_tree AVL;

// Cria uma árvore binária de busca vazia
AVL* avl_create(void);
// Insere um novo ITEM na árvore
bool avl_insert(AVL* T, ITEM* item);
// Percurso em pré-ordem: Raiz -> Esquerda -> Direita
void avl_preorder(ND* root);
// Percurso em ordem: Esquerda -> Raiz -> Direita
void avl_inorder(ND* root);
// Percurso em pós-ordem: Esquerda -> Direita -> Raiz
void avl_postorder(ND* root);
// Calcula a profundidade (altura) da árvore
int BT_depth(ND* r);

#endif
