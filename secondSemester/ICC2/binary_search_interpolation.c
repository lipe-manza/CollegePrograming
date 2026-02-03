#include <stdio.h>

// ===============================
// Interpolation Search - Iterativa
// ===============================
int interpolation_search_iter(int arr[], int inicio, int fim, int key) {
    while (inicio <= fim && key >= arr[inicio] && key <= arr[fim]) {
        if (inicio == fim) {
            if (arr[inicio] == key)
                return inicio;
            return -1;
        }

        int meio = inicio + ((key - arr[inicio]) * (fim - inicio)) / (arr[fim] - arr[inicio]);

        if (arr[meio] == key)
            return meio;
        else if (arr[meio] < key)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

// ===============================
// Interpolation Search - Recursiva
// ===============================
int interpolation_search_rec(int arr[], int inicio, int fim, int key) {
    if (inicio > fim || key < arr[inicio] || key > arr[fim])
        return -1;

    if (inicio == fim) {
        if (arr[inicio] == key)
            return inicio;
        return -1;
    }

    int meio = inicio + ((key - arr[inicio]) * (fim - inicio)) / (arr[fim] - arr[inicio]);

    if (arr[meio] == key)
        return meio;
    else if (arr[meio] < key)
        return interpolation_search_rec(arr, meio + 1, fim, key);
    else
        return interpolation_search_rec(arr, inicio, meio - 1, key);
}

// ===============================
// Função principal para teste
// ===============================
int main() {
    int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 70;

    int pos_iter = interpolation_search_iter(arr, 0, n - 1, key);
    int pos_rec = interpolation_search_rec(arr, 0, n - 1, key);

    if (pos_iter != -1)
        printf("Iterativa: elemento %d encontrado no índice %d\n", key, pos_iter);
    else
        printf("Iterativa: elemento %d não encontrado\n", key);

    if (pos_rec != -1)
        printf("Recursiva: elemento %d encontrado no índice %d\n", key, pos_rec);
    else
        printf("Recursiva: elemento %d não encontrado\n", key);

    return 0;
}
