//  Enzo Trulenque Evangelista - 15819219
//  Luiz Felipe Manzoli Franceschini - 16913300
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <stdbool.h>

// Gera o vetor aleatório
void random_vector(int v[], int n, int* seed) {
    for (int i = 0; i < n; i++) {
        v[i] = get_random(seed, n);
    }
}

// Verifica se o vetor ta ordenado 
bool sorted(int v[], int N) {
    for (int i = 0; i < N - 1; i++) {
        if (v[i] > v[i + 1]) return false;
    }
    return true;
}

// Funcao para embaralhar com indices aleatorios gerados pela get_random
void FisherYatesShuffle(int v[], int N, int* seed) {
    int j, aux;
    // Embaralha o vetor
    for (int i = N - 1; i >= 1; i--) {
        j = get_random(seed, i) - 1; //Gera o indice aleatorio
        // Swap
        aux = v[j];
        v[j] = v[i];
        v[i] = aux;
    }
}

int main() {
    int n, count = 0, seed = 12345;

    scanf(" %d", &n);

    int v[n];

    // Necessario passar a seed por referencia pois ela muda na funcao get_random e é preciso mudar para dar a resposta certa
    random_vector(v, n, &seed); // Cria um vetor com a funcao get_random

    while (!sorted(v, n)) { // Chama a funcao FisherYeatesShuffle verificando antes se o vetor nao esta ordenado
        FisherYatesShuffle(v, n, &seed);
        count++;
    }

    printf("%d\n", count);
    for (int i = 0; i < n; i++) {
        printf("%d%c", v[i], (i == n - 1) ? '\n' : ' '); // Para não dar \n final 
    }

    return 0;
}
