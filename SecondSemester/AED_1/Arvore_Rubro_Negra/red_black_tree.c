#include "red_black_tree.h"
//vermelho =1 pretro = 0
struct node {
    ITEM* item;
    int color;
    ND* left_child;
    ND* right_child;
};

struct redBlackTree {
    ND* root;
    int depth;
};

RBT* rbt_create() {
    RBT* T = (RBT*)malloc(sizeof(RBT));
    if (T == NULL) return NULL;

    T->root = (ND*)malloc(sizeof(ND));
    if (T->root == NULL) printf("fail to alocate memory for root");

    T->root = NULL;
    T->depth = -1;

    return T;
}

void invert_color(ND* r) {
    r->color = !r->color;
    if (r->left_child)
        r->left_child = !r->left_child->color;
    if (r->right_child)
        r->right_child = !r->right_child->color;
}

ND* right_rotation(ND* C) {
    ND* B = C->left_child;
    C->left_child = B->right_child;
    B->right_child = C;

    B->color = C->color;
    C->color = 1;

    return B;
}

ND* left_rotation(ND* A) {
    ND* B = A->right_child;
    A->left_child = B->left_child;
    B->left_child = A;

    B->color = A->color;
    A->color = 1;

    return B;
}

int is_red(ND* h) {
    if (h == NULL) return 0;
    return (h->color == 1);
}

ND* insert_node(ND* h, ITEM* data) {
    if (h == NULL) return create_node(data);
    if (item_get_chave(data) < item_get_chave(h->item))
        h->left_child = insert_node(h->left_child, data);
    else if (item_get_chave(data) > item_get_chave(h->item))
        h->right_child = insert_node(h->right_child, data);

    if (is_red(h->right_child) && !is_red(h->left_child))
        h = left_rotation(h);
    if (is_red(h->left_child) && is_red(h->left_child->left_child))
        h = right_rotation(h);
    if (is_red(h->right_child) && is_red(h->left_child))
        invert_color(h);

    return h;
}

bool rbt_insert(RBT* T, ITEM* data) {
    if (T == NULL) return false;

    T->root = insert_node(T->root, data);  
    if (T->root == NULL) return false;

    T->root->color = 1;  // raiz sempre preta

    return true;
}