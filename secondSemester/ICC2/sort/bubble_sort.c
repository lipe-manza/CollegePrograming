#include <stdio.h>

int main() {

    int n;

    printf("Write the size of the array:");
    scanf(" %d", &n);

    int p[n];
    printf("Write the %d numbers within the array:", n);

    int aux;
    for (int w = 0; w < n; w++) {
        scanf(" %d", &p[w]);
    }
    printf("\n");

    // Printing before the sort
    printf("****************\n");
    printf("Before the sort: {");
    for (int z = 0; z < n; z++) {
        printf("%d ", p[z]);
    }
    printf("}");
    printf("\n");
    printf("****************");
    printf("\n\n");


    /*  //*Bubble_sorting
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1 - j; i++) { // Decreasing the size of the reach
            if (p[i] > p[i + 1]) {
                aux = p[i + 1];
                p[i + 1] = p[i];
                p[i] = aux;
            }
        }
    }
    */

    //*Bubble_sorting melhorado
    int flag = 1;
    for (int j = 0; j < n && flag; j++) {//? "&& flag " Ensure the bubble sort avoids unnecessary repetitions.
        flag = 0;
        for (int i = 0; i < n - 1 - j; i++) {
            if (p[i] > p[i + 1]) {
                aux = p[i + 1];
                p[i + 1] = p[i];
                p[i] = aux;
                flag = 1;
            }
        }
    }

    // Printing after the sort
    printf("****************\n");
    printf("After the sort: {");
    for (int y = 0; y < n; y++) {
        printf("%d ", p[y]);
    }
    printf("}");
    printf("\n");
    printf("****************");


    return 0;
}