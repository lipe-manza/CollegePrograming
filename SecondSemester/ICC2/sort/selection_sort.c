#include <stdio.h> 

#include <stdio.h>

//? You have to iterate trough the whole array to find the minor number and put on the beggining of the array 
void direct_selection(int arr[], int n) {
    int i, j, aux, menor, indice;

    for (int j = 0; j < n; j++) {
        menor = arr[j];
        aux = arr[j];
        for (int i = j + 1; i < n; i++) {
            if (menor > arr[i]) {
                menor = arr[i];
                indice = i;
            }
        }
        if (menor != arr[j]) {
            arr[j] = menor;
            arr[indice] = aux;
        }
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


    direct_selection(vector, n);


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