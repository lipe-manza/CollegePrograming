#include "binary_tree.h"
#include <stdlib.h>
#include <stdbool.h> // needed for bool type

// Node structure
typedef struct node {
    ITEM* item;
    struct node* left;
    struct node* right;
} ND;

// Binary tree structure
struct binary_tree {
    ND* root;
    int depth;
};

// Create an empty binary tree
BT* bt_create(void) {
    BT* t = (BT*)malloc(sizeof(BT));
    if (t != NULL) {
        t->root = NULL;
        t->depth = -1; // -1 because there's no root yet
    }
    return t;
}

// Preorder traversal: Root -> Left -> Right
void bt_preorder(ND* root) {
    if (root) {
        print_item(root);
        bt_preorder(root->left);
        bt_preorder(root->right);
    }
}

// Inorder traversal: Left -> Root -> Right
void bt_inorder(ND* root) {
    if (root) {
        bt_inorder(root->left);
        print_item(root);
        bt_inorder(root->right);
    }
}

// Postorder traversal: Left -> Right -> Root
void bt_postorder(ND* root) {
    if (root) {
        bt_postorder(root->left);
        bt_postorder(root->right);
        print_item(root);
    }
}

// Define constants for child direction
#define LEFT_CHILD  0
#define RIGHT_CHILD 1

// Recursive function to insert a node at the correct position
void bt_insert_node(ND* root, ND* new_node, int side, int parent_key) {
    if (root != NULL) {
        // Traverse left and right subtrees
        bt_insert_node(root->left, new_node, side, parent_key); // Call the next left child
        bt_insert_node(root->right, new_node, side, parent_key); // CAll the next right child

        // Check if current node is the parent
        if (parent_key == item_get_key(root->item)) {
            if (side == LEFT_CHILD)
                root->left = new_node;  // insert on the left
            else if (side == RIGHT_CHILD)
                root->right = new_node; // insert on the right
        }
    }
}

// Public insert function
bool bt_insert(BT* t, ITEM* item, int side, int parent_key) {
    if (t->root == NULL) {
        // If there's no root, create it
        return ((t->root = bt_create_node(item)) != NULL);
    }
    else {
        ND* new_node = bt_create_node(item);
        if (new_node != NULL) {
            bt_insert_node(t->root, new_node, side, parent_key);
            return true;
        }
        return false;
    }
}

// Calculates the depth of the root of the Binary Tree
int BT_depth(ND* r) {
    if (r == NULL) return -1; // If node is NULL return -1 to compensate the + 1    
    int le = BT_depth(r->left);
    int ri = BT_depth(r->right);
    return ((le > ri) ? le : ri) + 1; // Return the greater depth + 1 to do the recursive call
}