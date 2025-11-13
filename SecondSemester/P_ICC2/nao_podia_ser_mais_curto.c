#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO  365000 // dias*
typedef struct node ND;

enum Algoritimo {
    Binaria = 1,
    Hashing,
    Sequencial
};

struct node {
    int data;
    ND* next_node;
};

typedef struct bucket {
    int date;
    bool has_data;
    ND* colision;
}BU;


int hash(int data) {
    int dias_ate_mes[] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

    int bucket = ((data % 100) + dias_ate_mes[(data / 100) % 100] * ((data / 1000) % 1000 + 1)); // Ira ter colisão a cada 1000 anos;

    return bucket;
}

void hash_table_insert(BU hash_table[], int data) {
    int bucket = hash(data);
    if (hash_table[bucket].has_data) {
        ND* new_node = (ND*)malloc(sizeof(ND));
        new_node->next_node = hash_table[bucket].colision;
        hash_table[bucket].colision = new_node;
        new_node->data = data;
    }
    else {
        hash_table[bucket].date = data;
        hash_table[bucket].has_data = true;
    }
}

bool search_in_hash_table() {

}


bool binary_search(int v[], int key, int n) {
    int end = n - 1;
    int start = 0;
    int mid;
    while (start < end) {
        mid = (end + start) / 2;
        if (v[mid] == key) {
            return true;
        }if (v[mid] < key) {
            end = mid;
        }
        else {
            start = mid;
        }
    }
    return false;
}

int main() {
    int N = 0;
    scanf("%d", &N);

    int dia[N], mes[N], ano[N];
    int datas[N];
    for (int i = 0; i < N; i++) {
        scanf(" %d-%d-%d", &dia[i], &mes[i], &ano[i]);
        datas[i] = dia[i] + mes[i] * 100 + ano[i] * 10000; // transforma no tipo yyyymmdd
    }

    int Q = 0;
    scanf(" %d", &Q);
    int diab[Q], mesb[Q], anob[Q];
    int datas_buscar[N];
    for (int i = 0; i < Q; i++) {
        scanf(" %d-%d-%d", &diab[i], &mesb[i], &anob[i]);
        datas_buscar[N] = diab[i] + mesb[i] * 100 + anob[i] * 10000; // transforma no tipo yyyymmdd
    }

    int op;
    scanf(" %d", &op);

    if (op == Hashing) {
        BU hash_table[TAMANHO] = { 0 };// Formando a hash_table
        for (int i = 0; i < N; i++) {
            hash_table_insert(hash_table, datas[i]);
        }
    }
    else if (op == Sequencial) {

    }

}