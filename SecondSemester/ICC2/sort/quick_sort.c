#include <stdio.h>
#include <stdlib.h>


void quick_sort(int* vector, int inicio, int fim) {
    int l = inicio;
    int r = fim;
    int pivo = vector[(inicio + fim) / 2];
    int aux;

    if (inicio >= fim) {
        return;
    }

    while (l <= r) {
        while (vector[l] < pivo) l++;
        while (vector[r] > pivo) r--;
        if (l <= r) {
            aux = vector[l];
            vector[l] = vector[r];
            vector[r] = aux;
            l++;
            r--;
        }
    }
    if (inicio < r) quick_sort(vector, inicio, r);

    if (l < fim) quick_sort(vector, l, fim);

}


int main() {

    int n;
    printf("Write the size of the array:");
    scanf(" %d", &n);

    int vector[n];

    printf("Write the %d numbers within the array:", n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &vector[i]);
    }
    printf("\n");

    printf("****************\n");
    printf("Before the sort: {");
    for (int z = 0; z < n; z++) {
        printf("%d ", vector[z]);
    }
    printf("}");
    printf("\n");
    printf("****************");
    printf("\n\n");


    quick_sort(vector, 0, n - 1);


    printf("****************\n");
    printf("After the sort: {");
    for (int y = 0; y < n; y++) {
        printf("%d ", vector[y]);
    }
    printf("}");
    printf("\n");
    printf("****************");


    return 0;

}