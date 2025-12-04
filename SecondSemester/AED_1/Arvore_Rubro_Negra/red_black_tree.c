#include "red_black_tree.h"
//vermelho =1 pretro = 0
struct node {
    ITEM* item;
    int color;
    ND* leftC;
    ND* rightC;
};

struct redBlackTree {
    ND* root;
    int depth;
};

RBT* rbtCreate() {
    RBT* T = (RBT*)malloc(sizeof(RBT));
    if (T == NULL) return NULL;

    T->root = NULL;
    T->depth = -1;

    return T;
}

ND* create_node(ITEM* x) {
    ND* h = malloc(sizeof(ND));
    h->item = x;
    h->color = 1; // vermelho
    h->leftC = h->rightC = NULL;
    return h;
}

void invertColor(ND* r) {
    r->color = !r->color;
    if (r->leftC)
        r->leftC->color = !r->leftC->color;
    if (r->rightC)
        r->rightC->color = !r->rightC->color;
}

ND* rightRotation(ND* C) {
    ND* B = C->leftC;
    C->leftC = B->rightC;
    B->rightC = C;

    B->color = C->color;
    C->color = 1;

    return B;
}

ND* leftRotation(ND* A) {
    ND* B = A->rightC;
    A->rightC = B->leftC;
    B->leftC = A;

    B->color = A->color;
    A->color = 1;

    return B;
}

int isRed(ND* h) {
    if (h == NULL) return 0;
    return (h->color == 1);
}

ND* insert_node(ND* h, ITEM* data) {
    if (h == NULL) return create_node(data);
    if (item_get_chave(data) < item_get_chave(h->item))
        h->leftC = insert_node(h->leftC, data);
    else if (item_get_chave(data) > item_get_chave(h->item))
        h->rightC = insert_node(h->rightC, data);
    else {
        // NOVO: Rejeitar duplicata
        item_apagar(&data);
        return NULL;
    }

    if (isRed(h->rightC) && !isRed(h->leftC))
        h = leftRotation(h);
    if (isRed(h->leftC) && isRed(h->leftC->leftC))
        h = rightRotation(h);
    if (isRed(h->rightC) && isRed(h->leftC))
        invertColor(h);

    return h;
}

bool rbtInsert(RBT* T, ITEM* data) {
    if (T == NULL) return false;

    T->root = insert_node(T->root, data);
    if (T->root == NULL) return false;

    T->root->color = 0;  // raiz sempre preta

    return true;
}

// Funcoes auxiliares para a remocao 
ND* propagateRight(ND* h) {
    if (isRed(h->leftC))
        h = rightRotation(h);
    if (!isRed(h->rightC) && !isRed(h->rightC->leftC)) {
        invertColor(h);
        if (isRed(h->leftC->leftC)) {
            h = rightRotation(h);
            invertColor(h);
        }
    }
    return h;
}


ND* propagateLeft(ND* h) {
    if (!isRed(h->leftC) && !isRed(h->leftC->leftC)) {
        invertColor(h);
        if (isRed(h->rightC->leftC)) {
            h->rightC = rightRotation(h->rightC);
            h = leftRotation(h);
            invertColor(h);
        }
    }
    return h;
}

ND* restore(ND* h) {
    if (isRed(h->rightC) && !isRed(h->leftC))
        h = leftRotation(h);
    if (isRed(h->leftC) && isRed(h->leftC->leftC))
        h = rightRotation(h);
    if (isRed(h->rightC) && isRed(h->leftC))
        invertColor(h);

    return h;
}

ND* min(ND* h) {
    while (h->leftC) {
        h = h->leftC;
    }
    return h;
}

ND* removeMin(ND* h) {
    if (h->leftC == NULL) {
        item_apagar(&h->item);
        free(h);
        h = NULL;
        return h;
    }
    if (!isRed(h->leftC) && !isRed(h->leftC->leftC))
        h = propagateLeft(h);

    h->leftC = removeMin(h->leftC);

    return restore(h);
}

ND* deletNode(ND* r, int key) {
    if (r == NULL) return (NULL);

    if (item_get_chave(r->item) == key) {
        // Caso folha e 1 só filho
        if (r->leftC == NULL || r->rightC == NULL) {
            ND* p = r;
            if (r->leftC == NULL)
                r = r->rightC;
            else
                r = r->leftC;
            item_apagar(&p->item);  // NOVO: Liberar o item
            free(p);
            p = NULL;
        }// Caso 2 filhos
        else {
            r = propagateRight(r);
            ND* x = min(r->rightC);
            item_apagar(&r->item);  // NOVO: Liberar item antigo antes de trocar
            r->item = x->item; // Troca as chaves
            r->rightC = removeMin(r->rightC);
        }
    }
    else {
        if (key < item_get_chave(r->item)) {
            r = propagateLeft(r);
            r->leftC = deletNode(r->leftC, key);
        }
        else {
            r = propagateRight(r);
            r->rightC = deletNode(r->rightC, key);
        }
    }
    if (r != NULL)
        r = restore(r);

    return r;
}

/* Função pública de remoção para a árvore inteira  */
bool rbtRemove(RBT* T, int key) {
    if (T == NULL || T->root == NULL) return false;

    ND* oldRoot = T->root;
    T->root = deletNode(T->root, key);

    if (T->root)
        T->root->color = 0; // raiz preta

    return oldRoot != T->root;  // NOVO: Retorna true apenas se mudou
}

int quant_elementos(ND* r) {
    if (r == NULL)
        return 0;

    return 1 + quant_elementos(r->leftC) + quant_elementos(r->rightC);

}

int maior_elemento(ND* r) {
    if (r == NULL) return -10000000;

    int maiorL = maior_elemento(r->leftC);
    int maiorR = maior_elemento(r->rightC);

    int Omaior = (maiorL < maiorR) ? maiorR : maiorL;
    if (item_get_chave(r->item) < Omaior) {
        return Omaior;
    }
    else
        return item_get_chave(r->item);
}

int menor_elemento(ND* r) {
    if (r == NULL) return 100000000;

    int menorL = menor_elemento(r->leftC);
    int menorR = menor_elemento(r->rightC);

    int Omenor = (menorL > menorR) ? menorR : menorL;
    if (item_get_chave(r->item) > Omenor) {
        return Omenor;
    }
    else
        return item_get_chave(r->item);
}

int soma_todos(ND* r) {
    if (r == NULL) return 0;

    return item_get_chave(r->item) + soma_todos(r->leftC) + soma_todos(r->rightC);
}