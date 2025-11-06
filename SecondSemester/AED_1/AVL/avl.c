#include "avl.h"
#include <stdbool.h> // needed for bool type
#include <stdlib.h>

// Node structure
struct node {
    ITEM* item;
    int height; // to Calculate the balance_factor //if(balance_factor>=2) right_rotation; else if(balance_factor<=-2) left_rotation;
    ND* left;
    ND* right;
};

// Binary tree structure
struct binary_balanced_search_tree {
    ND* root;
    int depth;
};

// Create an empty binary tree
AVL* avl_create(void) {
    AVL* t = (AVL*)malloc(sizeof(AVL));
    if (t != NULL) {
        t->root = NULL;
        t->depth = -1; // -1 because there's no root yet
    }
    return t;
}

ND* avl_create_node(ITEM* item) {
    ND* new_node = (ND*)malloc(sizeof(ND));
    if (new_node) {
        if (item != NULL) {
            new_node->item = item;
        }
        new_node->height = 0;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

void avl_delete_aux(ND* root) {
    if (root != NULL) {
        avl_delete_aux(root->left);
        avl_delete_aux(root->right);
        item_apagar(&root->item);
        free(root);
    }
}

void delete_avl(AVL** T) {
    if (T) {
        avl_delete_aux((*T)->root);
        free(*T);
    }
}

int avl_nd_height(ND* root) {
    if (root == NULL) {
        return -1;
    }
    else {
        return root->height;
    }
}

ND* right_rotation(ND* A) {
    ND* B = A->left;
    A->left = B->right;
    B->right = A;

    A->height = (A->left->height > A->left->height) ? A->left->height + 1 : A->right->height + 1;
    return B;

}

ND* left_rotation(ND* A) {
    ND* B = ;
    A->left = B->right;
    B->right = A;

    A->height = (A->left->height > A->left->height) ? A->left->height + 1 : A->right->height + 1;
    return B;

}

ND* left_right_rotation(ND* A) {
    A->left = left_rotation(A->left);
    return right_rotation(A);
}

ND* right_left_rotation(ND* A) {

}
// Preorder traversal: Root -> Left -> Right
void avl_preorder(ND* root) {
    if (root) {
        print_item(root);
        avl_preorder(root->left);
        avl_preorder(root->right);
    }
}

// Inorder traversal: Left -> Root -> Right
void avl_inorder(ND* root) {
    if (root) {
        avl_inorder(root->left);
        print_item(root);
        avl_inorder(root->right);
    }
}

// Postorder traversal: Left -> Right -> Root
void avl_postorder(ND* root) {
    if (root) {
        avl_postorder(root->left);
        avl_postorder(root->right);
        print_item(root);
    }
}

// Recursive function to insert a node passing per value
ND* avl_insert_node(ND* root, ND* new_node) { // It is linking the arrows backwards
    if (root == NULL)
        root = new_node;
    else if (item_get_chave(new_node) < item_get_chave(root->item))
        root->left = avl_insert_node(root->left, new_node);
    else if (item_get_chave(new_node) > item_get_chave(root->item))
        root->right = avl_insert_node(root->right, new_node);

    // updating the height of each node recursively
    int lh = avl_nd_height(root->left) + 1;
    int rh = avl_nd_height(root->right) + 1;
    root->height = (lh > rh) ? lh : rh;
    // Balance Factor
    int BF = lh - rh;

    if (BF == -2) {
        if (avl_nd_height(root->right->left) - avl_nd_height(root->right->right) > 0) {
            root = left_right_rotation(root);
        }
        else {
            root = left_rotation(root);
        }
    }
    if (BF == 2) {
        if (avl_nd_height(root->left->right) - avl_nd_height(root->left->right) < 0) {
            root = right_left_rotation(root);
        }
        else {
            root = right_rotation(root);
        }
    }

    return root;
}

// Recursive function to insert a node passing per reference
// void avl_insert_node(ND **root, ND *new_node) {
//   if (*root == NULL)
//     *root = new_node;
//   else if (item_get_chave(new_node) < item_get_chave(&(*root)->item))
//     avl_insert_node(&(*root)->left, new_node);
//   else if (item_get_chave(new_node) > item_get_chave(&(*root)->item))
//     avl_insert_node(&(*root)->right, new_node);
// }

// Public insert function
bool avl_insert(AVL* T, ITEM* item) {
    ND* new_node;
    if (T == NULL)
        return false;
    new_node = avl_create_node(item);
    if (new_node != NULL) {
        T->root = avl_insert_node(T->root, new_node);
        return true;
    }
    return false;
}


// Calculates the depth of the root of the Binary Tree
int AVL_calc_depth(ND* r) {
    if (r == NULL)
        return -1; // If node is NULL return -1 to compensate the + 1
    int le = AVL_calc_depth(r->left);
    int ri = AVL_calc_depth(r->right);

    return le - ri;
}

ITEM* avl_search2(ND* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key == item_get_chave(root->item)) {
        return root->item;
    }

    if (key < item_get_chave(root->item)) {
        return avl_search(root->left, key);
    }
    else {
        return avl_search(root->right, key);
    }
}

// Best case: All Balance (log n)
ITEM* avl_search(ND* root, int key) {
    return avl_search2(root, key);
}

void swap_left_max(ND* t, ND* r, ND* a) {
    if (t->right != NULL) {
        swap_left_max(t->right, r, t);
    }
    if (a == r)
        a->left = t->left;
    else
        a->right = t->left;

    r->left = t->item;
    free(t);
    t = NULL;
}

ITEM* bst_remove2(ND** root, int key) {
    ND* p;
    ITEM* item;
    if (*root == NULL) return NULL;
    if (key == item_get_chave((*root)->item))
    {
        item = (*root)->item;
        if ((*root)->left == NULL || (*root)->right == NULL)// se tem um ou 0 filhos
        {
            p = *root;
            if ((*root)->left == NULL)
            {
                (*root) = (*root)->right;
            }
            else {
                (*root) = (*root)->left;
            }
            free(p);
            p = NULL;
        }
        else {// Ambos os filhos
            swap_left_max((*root)->left, (*root), (*root));
            return item;
        }
    }
    else {
        if (key < item_get_chave((*root)->item))
            return bst_remove2(&(*root)->left, key);
        else
            return bst_remove2(&(*root)->right, key);
    }
}

ITEM* bst_remove(AVL* T, int key) {
    if (T != NULL) {
        return bst_remove2(&(T->root), key);
    }
    else
        return NULL;
}