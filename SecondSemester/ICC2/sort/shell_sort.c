#include <stdio.h>

void shell_sort(int arr[], int n) {
    int h = 1;

    // Calcula maior h de Knuth < n
    while (h < n / 3) {
        h = 3 * h + 1;
    }

    // Aplica o Shell Sort
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= h && arr[j - h] > temp; j -= h) {
                arr[j] = arr[j - h];
            }
            arr[j] = temp;
        }
        h = h / 3; // diminui o gap
    }
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


    shell_sort(vector, n);


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