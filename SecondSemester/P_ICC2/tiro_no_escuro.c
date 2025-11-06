//  Enzo Trulenque Evangelista - 15819219
//  Luiz Felipe Manzoli Franceschini - 16913300
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "util.h"

// Função auxiliar para trocar elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insertion Sort para vetores pequenos
void insertion_sort(int v[], int inicio, int fim) {
    for (int i = inicio + 1; i <= fim; i++) {
        int chave = v[i];
        int j = i - 1;

        while (j >= inicio && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

// Função para construir o heap máximo
void heapify(int v[], int n, int i) {
    int maior = i;
    int e = 2 * i + 1;
    int d = 2 * i + 2;

    if (e < n && v[e] > v[maior])
        maior = e;

    if (d < n && v[d] > v[maior])
        maior = d;

    if (maior != i) {
        swap(&v[i], &v[maior]);
        heapify(v, n, maior);
    }
}

// Heap Sort para quando a profundidade limite é atingida
void heap_sort(int v[], int inicio, int fim) {
    int n = fim - inicio + 1;

    // Constrói o heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v + inicio, n, i);

    // Extrai elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        swap(&v[inicio], &v[inicio + i]);
        heapify(v + inicio, i, 0);
    }
}

// Partição para Quicksort (usando mediana de três)
int partition(int v[], int inicio, int fim) {
    // Escolhe o pivo como a mediana entre v[inicio], v[m] e v[fim]
    int m = inicio + (fim - inicio) / 2;

    // Ordena inicio, m, fim
    if (v[inicio] > v[m])
        swap(&v[inicio], &v[m]);
    if (v[m] > v[fim])
        swap(&v[m], &v[fim]);
    if (v[inicio] > v[m])
        swap(&v[inicio], &v[m]);

    // Coloca o pivo na penúltima posição
    swap(&v[m], &v[fim - 1]);
    int pivo = v[fim - 1];

    int i = inicio;
    int j = fim - 1;

    while (1) {
        do {
            i++;
        } while (v[i] < pivo);

        do {
            j--;
        } while (v[j] > pivo);

        if (i >= j) break;

        swap(&v[i], &v[j]);
    }

    // Coloca o pivo na posição correta
    swap(&v[i], &v[fim - 1]);
    return i;
}

// Função recursiva do Introsort
void introsort_recursive(int v[], int inicio, int fim, int prof_limite) {
    int size = fim - inicio + 1;

    // Caso base: vetores pequenos usam Insertion Sort
    if (size < 16) {
        insertion_sort(v, inicio, fim);
        return;
    }

    // Se a profundidade limite foi atingida, usa Heap Sort
    if (prof_limite == 0) {
        heap_sort(v, inicio, fim);
        return;
    }

    // Caso contrário, usa Quicksort
    int indice_pivo = partition(v, inicio, fim);

    // Recursão para as partições esquerda e direita
    introsort_recursive(v, inicio, indice_pivo - 1, prof_limite - 1);
    introsort_recursive(v, indice_pivo + 1, fim, prof_limite - 1);
}

// Função principal do Introsort para caso 2
void introsort(int v[], int n) {
    if (n <= 1) return;

    // Calcula o limite de profundidade (2 * log2(n))
    int prof_limite = 2 * (int)log2(n);
    introsort_recursive(v, 0, n - 1, prof_limite);
}

// Funcao quick_sort para caso 3
void quick_sort(int v[], int inicio, int fim) {
    if (inicio >= fim) return;

    int pivo = v[(inicio + fim) / 2]; //pivo é o elemento do meio

    int e = inicio;
    int d = fim;

    while (e <= d) {
        while (v[e] < pivo) e++;
        while (v[d] > pivo) d--;
        if (e <= d) {
            int temp = v[e];
            v[e] = v[d];
            v[d] = temp;
            e++;
            d--;
        }
    }
    if (fim > e) quick_sort(v, e, fim);
    if (inicio < d) quick_sort(v, inicio, d);
}

// shell_sort para caso 1
void shell_sort(int v[], int n) {
    int aux, j, h = 1;
    // metodo de knuth
    while (h < n) {
        h = h * 3 + 1;
    }

    while (h >= 1) {
        for (int i = h; i < n; i++) {
            aux = v[i];
            for (j = i; j >= h && v[j - h] > aux; j -= h)
                v[j] = v[j - h];
            v[j] = aux;
        }
        h /= 3;
    }
}

// Funcoes para gerar os vetores (random , reverse e sorted)
void gerar_random(int v[], int n) {
    int seed = 12345;
    for (int i = 0; i < n; i++) {
        v[i] = get_random(&seed, n);
    }
}

void gerar_reverse(int v[], int n) {
    for (int i = 1; i <= n; i++)
        v[n - i] = i;
}

void gerar_sorted(int v[], int n) {
    for (int i = 0; i < n; i++)
        v[i] = i + 1;
}

//Funcao ordenar que agrupa a criacao dos vetores e a chamada das funcoes de ordenacao
void ordenar(int v[], char* tipo, int op, int n) {
    if (strcmp(tipo, "reverse") == 0)
        gerar_reverse(v, n);
    else if (strcmp(tipo, "random") == 0)
        gerar_random(v, n);
    else if (strcmp(tipo, "sorted") == 0)
        gerar_sorted(v, n);

    switch (op) {
    case 1: shell_sort(v, n); break; // op = 1 → Shell Sort
    case 2: introsort(v, n); break; // op = 2 → Introsort
    case 3: quick_sort(v, 0, n - 1); break; // op = 3 → Quick Sort
    }
}

int main() {
    int n = 0;  // Tamanho do array
    char tipo[10]; // Tipo do array
    int op = 0; //Operacao a ser chamada para ordenar
    scanf(" %d", &n);
    scanf(" %s", tipo);
    scanf(" %d", &op);

    int* v = (int*)malloc(n * sizeof(int)); // Alocando memoria para casos muito grandes nao estourarem a stack
    if (v == NULL) return 1;

    ordenar(v, tipo, op, n); // Chamada da funcao que ordena e cria os vetores

    // Funcoes do util.h
    init_crc32();
    uint32_t saida = crc32(0, v, n * sizeof(int));
    printf("%08X\n", saida); // Printa o hash da sequencia ordenada segundo o CRC32

    free(v); // Da free no array
    return 0;
}