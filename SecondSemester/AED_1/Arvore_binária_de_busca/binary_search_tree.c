#include "binary_search_tree.h"
#include <stdbool.h> // needed for bool type
#include <stdlib.h>

// Node structure
typedef struct node {
  ITEM* item;
  struct node* left;
  struct node* right;
} ND;

// Binary tree structure
struct binary_search_tree {
  ND* root;
  int depth;
};

// Create an empty binary tree
BST* bst_create(void) {
  BST* t = (BST*)malloc(sizeof(BST));
  if (t != NULL) {
    t->root = NULL;
    t->depth = -1; // -1 because there's no root yet
  }
  return t;
}

ND* bst_create_node(ITEM* item) {
  ND* new_node = (ND*)malloc(sizeof(ND));
  if (new_node) {
    if (item != NULL) {
      new_node->item = item;
    }
  }
}

// Preorder traversal: Root -> Left -> Right
void bst_preorder(ND* root) {
  if (root) {
    print_item(root);
    bst_preorder(root->left);
    bst_preorder(root->right);
  }
}

// Inorder traversal: Left -> Root -> Right
void bst_inorder(ND* root) {
  if (root) {
    bst_inorder(root->left);
    print_item(root);
    bst_inorder(root->right);
  }
}

// Postorder traversal: Left -> Right -> Root
void bst_postorder(ND* root) {
  if (root) {
    bst_postorder(root->left);
    bst_postorder(root->right);
    print_item(root);
  }
}

// Recursive function to insert a node passing per value
ND* bst_insert_node(ND* root, ND* new_node) { // It is linking the arrows backwards
  if (root == NULL)
    root = new_node;
  else if (item_get_chave(new_node) < item_get_chave(root->item))
    root->left = bst_insert_node(root->left, new_node);
  else if (item_get_chave(new_node) > item_get_chave(root->item))
    root->right = bst_insert_node(root->right, new_node);
  return root;
}
// Recursive function to insert a node passing per reference
// void bst_insert_node(ND **root, ND *new_node) {
//   if (*root == NULL)
//     *root = new_node;
//   else if (item_get_chave(new_node) < item_get_chave(&(*root)->item))
//     bst_insert_node(&(*root)->left, new_node);
//   else if (item_get_chave(new_node) > item_get_chave(&(*root)->item))
//     bst_insert_node(&(*root)->right, new_node);
// }

// Public insert function
bool bst_insert(BST* T, ITEM* item) {
  ND* new_node;
  if (T == NULL)
    return false;
  new_node = bst_create_node(item);
  if (new_node != NULL) {
    T->root = bst_insert_node(T->root, new_node);
    return true;
  }
  return false;
}

// Calculates the depth of the root of the Binary Tree
int BT_depth(ND* r) {
  if (r == NULL)
    return -1; // If node is NULL return -1 to compensate the + 1
  int le = BT_depth(r->left);
  int ri = BT_depth(r->right);
  return ((le > ri) ? le : ri) + 1; // Return the greater depth + 1 to do the recursive call
}

ITEM* bst_search2(ND* root, int key) {
  if (root == NULL) {
    return NULL;
  }
  if (key == item_get_chave(root->item)) {
    return root->item;
  }

  if (key < item_get_chave(root->item)) {
    return bst_search(root->left, key);
  }
  else {
    return bst_search(root->right, key);
  }
}

// Best case: All Balance (log n)
ITEM* bst_search(ND* root, int key) {
  return bst_search2(root, key);
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

ITEM* bst_remove(BST* T, int key) {
  if (T != NULL) {
    return bst_remove2(&(T->root), key);
  }
  else
    return NULL;
}