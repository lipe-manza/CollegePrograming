#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define RANGE 6200
typedef struct node ND;

enum Algorithm {
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
} BU;
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int compare_ints(const void* a, const void* b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return ia - ib;
}

int hash(int data) {
    int bucket = 0;
    return bucket = ((data / 10000) % 200 ) * 31  +(data%100);

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

bool search_in_hash_table(BU hash_table[], int key) {
    if (!hash_table) return 0;

    int bucket = hash(key);

    if (hash_table[bucket].date == key) return true;

    ND* aux = hash_table[bucket].colision;
    while (aux != NULL) {
        if (aux->data == key) return true;
        aux = aux->next_node;
    }

    return false;
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

bool sequencial_sort(int vector[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (vector[i] == key) return true;
    }

    return false;
}

int main() {
    int N = 0;
    scanf("%d", &N);

    int day[N], month[N], year[N];
    int* dates = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf(" %d-%d-%d", &day[i], &month[i], &year[i]);
        dates[i] = day[i] + month[i] * 100 + year[i] * 10000; // transforma no tipo yyyymmdd
    }

    int Q = 0;
    scanf(" %d", &Q);
    int dayb[Q], monthb[Q], yearb[Q];
    int* search_dates = (int*)malloc(Q * sizeof(int));
    for (int i = 0; i < Q; i++) {
        scanf(" %d-%d-%d", &dayb[i], &monthb[i], &yearb[i]);
        search_dates[i] = dayb[i] + monthb[i] * 100 + yearb[i] * 10000; // transforma no tipo yyyymmdd
    }

    int op;
    scanf(" %d", &op);
    bool found = false;

    if (op == Binaria) {
        qsort(dates, N, sizeof(int), compare_ints);

        for (int i = 0; i < Q; i++) {
            found = binary_search(dates,  search_dates[i], N);
            if (found) printf("ENCONTRADA\n");
            else printf("NAO_ENCONTRADA\n");
        }
    }
    else if (op == Hashing) {
        BU* hash_table = calloc(RANGE, sizeof(BU));// Formando a hash_table zerando todos os campos
        for (int i = 0; i < N; i++) {
            hash_table_insert(hash_table, dates[i]);
        }
        for (int i = 0; i < Q; i++) {
            found = search_in_hash_table(hash_table, search_dates[i]);
            if (found) printf("ENCONTRADA\n");
            else printf("NAO_ENCONTRADA\n");
        }
    }
    else {
        for (int i = 0; i < Q; i++) {
            found = sequencial_sort(dates, N, search_dates[i]);
            if (found) printf("ENCONTRADA\n");
            else printf("NAO_ENCONTRADA\n");
        }
    }

    return 0;
}