#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void quickSort(int vector[], int start, int end) {
    int l = start;
    int r = end;
    int m = (r + l) / 2;
    int pivo = vector[m];

    while (l <= r) {
        while (vector[l] < pivo)l++;
        while (vector[r] > pivo)r--;

        if (l <= r) {
            swap(&vector[l], &vector[r]);
            l++;
            r--;
        }

    }
    if (start < r) quickSort(vector, start, r);
    if (l < end) quickSort(vector, l, end);
}



bool quadraticTwoSum(int v[], int key, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] + v[j] == key) return true;

    return false;
}

int main() {
    int N, Q, key;
    scanf("%d", &N);

    int* vector = (int*)malloc(N * sizeof(int));
    if (vector == NULL) return 1;

    for (int i = 0; i < N; i++) {
        scanf(" %d", &vector[i]);
    }

    quickSort(vector, 0, N - 1);

    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        scanf(" %d", &key);
        printf(" %s\n", ((quadraticTwoSum(vector, key, N) ? "S" : "N")));
    }

    return 0;
}