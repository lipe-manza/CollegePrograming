#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição do tamanho da tabela hash
#define RANGE 6300 

// Enumeração para tipos de busca
enum search_type {
    BINARIA = 1,
    HASHING = 2,
    SEQUENCIAL = 3
};

// Estrutura do nó da lista de colisão
typedef struct node {
    int data;
    struct node* next_node;
} ND;

// Estrutura do bucket da tabela hash
typedef struct bucket {
    int date;
    bool has_data;
    ND* colision;
} BU;

// Função de comparação para qsort
int compare_ints(const void* a, const void* b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

// Função hash
int hash(int data) {
    return ((data / 10000) % 200) * 31 + (data % 100); // Ano * 31 + Dia/Mês
}

// Função para inserir na tabela hash
void hash_table_insert(BU hash_table[], int data) {
    // Verificar se a tabela é nula
    if (!hash_table) return;
    // Calcular o bucket
    int bucket = hash(data);
    // Inserir o dado no bucket
    if (hash_table[bucket].has_data) { // Colisão
        ND* new_node = (ND*)malloc(sizeof(ND));
        if (!new_node) return;
        new_node->data = data;
        new_node->next_node = hash_table[bucket].colision;
        hash_table[bucket].colision = new_node;
    }
    else { // Sem colisão
        hash_table[bucket].date = data;
        hash_table[bucket].has_data = true;
    }
}

// Função para busca na tabela hash
bool search_in_hash_table(BU hash_table[], int key) {
    if (!hash_table) return false;
    // Calcular o bucket
    int bucket = hash(key);
    // Verificar se o bucket contém a chave
    if (hash_table[bucket].has_data && hash_table[bucket].date == key) return true;
    // Verificar na lista de colisão
    ND* aux = hash_table[bucket].colision;
    // Percorrer a lista de colisão
    while (aux != NULL) {
        if (aux->data == key) return true;
        aux = aux->next_node;
    }
    return false;
}

// Função para busca binária
bool binary_search(int v[], int key, int n) {
    int start = 0, end = n - 1;
    // Loop de busca binária
    while (start <= end) {
        // 
        int mid = start + (end - start) / 2;

        if (v[mid] == key)
            return true;
        else if (v[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

// Função para busca sequencial
bool sequencial_search(int vector[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (vector[i] == key)
            return true;

    return false;
}

// Função para liberar a memória alocada para a tabela hash
void free_hash_table(BU hash_table[]) {
    // Verificar se a tabela é nula
    if (!hash_table) return;
    // Liberar listas de colisão
    for (int i = 0; i < RANGE && hash_table[i].has_data; i++) {
        // Liberar lista de colisão
        ND* aux = hash_table[i].colision;
        // Percorrer e liberar cada nó
        while (aux) {
            ND* tmp = aux->next_node;
            free(aux);
            aux = tmp;
        }
    }
    free(hash_table);
}

int main() {
    // Ler o número de datas
    int N;
    if (scanf("%d", &N) != 1) return 0;

    // Alocar vetor para datas
    int* dates = malloc(sizeof(int) * N);
    if (!dates) return 0;

    // Ler as datas
    for (int i = 0; i < N; i++) {
        int d, m, y;
        if (scanf(" %d-%d-%d", &d, &m, &y) != 3) { free(dates); return 0; }
        dates[i] = d + m * 100 + y * 10000;
    }

    // Ler o número de consultas
    int Q;
    if (scanf("%d", &Q) != 1) {
        free(dates);
        return 0;
    }

    // Alocar vetor para datas a serem buscadas
    int* search_dates = malloc(sizeof(int) * Q);
    if (!search_dates) {
        free(dates);
        return 0;
    }

    // Ler as datas a serem buscadas
    for (int i = 0; i < Q; i++) {
        int d, m, y;
        if (scanf(" %d-%d-%d", &d, &m, &y) != 3) {
            free(dates);
            free(search_dates);
            return 0;
        }
        // Armazenar a data no formato yyyymmdd
        search_dates[i] = d + m * 100 + y * 10000;
    }

    // Ler o tipo de busca
    int op;
    // Verificar se a leitura foi bem sucedida
    if (scanf("%d", &op) != 1) {
        free(dates);
        free(search_dates);
        return 0;
    }

    bool found = false;

    if (op == BINARIA) { // Binaria
        // Sortear o vetor de datas
        qsort(dates, N, sizeof(int), compare_ints);
        // Realizar buscas binarias
        for (int i = 0; i < Q; i++) {
            found = binary_search(dates, search_dates[i], N);
            printf(found ? "ENCONTRADA\n" : "NAO_ENCONTRADA\n");
        }
    }
    else if (op == HASHING) { // Hashing
        // Criar tabela hash e inserir datas
        BU* hash_table = calloc(RANGE, sizeof(BU));
        // Verificar se a alocação foi bem sucedida
        if (!hash_table) {
            free(dates);
            free(search_dates);
            return 0;
        }
        // Inserir datas na tabela hash
        for (int i = 0; i < N; i++)
            hash_table_insert(hash_table, dates[i]);
        // Realizar buscas na tabela hash
        for (int i = 0; i < Q; i++) {
            found = search_in_hash_table(hash_table, search_dates[i]);
            printf(found ? "ENCONTRADA\n" : "NAO_ENCONTRADA\n");
        }
        // Liberar memória da tabela hash
        free_hash_table(hash_table);
    }
    else { // Sequencial
        // Realizar buscas sequenciais
        for (int i = 0; i < Q; i++) {
            found = sequencial_search(dates, N, search_dates[i]);
            printf(found ? "ENCONTRADA\n" : "NAO_ENCONTRADA\n");
        }
    }

    // Liberar memória
    free(dates);
    free(search_dates);
    return 0;
}