#include <stdio.h>

void simple_insertion(int* x, int n) {
    int aux = 0, i, j;

    for (int j = 1; j < n; j++) {
        aux = x[j];
        for (i = j - 1; i >= 0 && aux < x[i]; i--) {
            x[i + 1] = x[i];
        }
        x[i + 1] = aux;
    }
    return x;

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


    simple_insertion(vector, n);


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