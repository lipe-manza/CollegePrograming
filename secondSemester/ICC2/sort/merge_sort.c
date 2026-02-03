#include <stdio.h>
#include <stdlib.h>

// Função para mesclar dois subarrays ordenados
void merge(int v[], int l, int m, int r) {
    int n1 = m - l + 1; // tamanho do subarray esquerdo
    int n2 = r - m;     // tamanho do subarray direito

    int L[n1], R[n2];   // arrays temporários

    // Copiando os elementos para os arrays temporários
    for (int i = 0; i < n1; i++) L[i] = v[l + i];
    for (int j = 0; j < n2; j++) R[j] = v[m + 1 + j];

    // Mesclando os arrays temporários de volta em v[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            v[k++] = L[i++];
        else
            v[k++] = R[j++];
    }

    // Copiando os elementos restantes, se houver
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
}

// Função principal do Merge Sort
void mergeSort(int v[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // índice do meio

        // Ordena recursivamente as duas metades
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);

        // Mescla as duas metades ordenadas
        merge(v, l, m, r);
    }
}

// Função para imprimir o array
void printArray(int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

// Teste do Merge Sort
int main() {
    int v[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Array original:\n");
    printArray(v, n);

    mergeSort(v, 0, n - 1);

    printf("Array ordenado:\n");
    printArray(v, n);

    return 0;
}