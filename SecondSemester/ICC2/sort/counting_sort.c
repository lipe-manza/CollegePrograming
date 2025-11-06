#include <stdio.h>
#include <string.h>

void counting_sort(int arr[], int n) {
    int menor = arr[0], maior = arr[0];

    // Acha o maior e o menor
    for (int i = 0; i < n; i++) {
        if (maior < arr[i]) maior = arr[i];
        if (menor > arr[i]) menor = arr[i];
    }

    // Acha o range do array
    int range = maior - menor + 1;

    // Cria  array auxiliar
    int count[range];
    memset(count, 0, range * sizeof(int));// zera o array inicializado

    // Conta a frequencia de cada valor no array
    for (int i = 0; i < n; i++) {
        count[arr[i] - menor]++; //- menor para aceitar números negativos também
    }

    // Reconstroi o arretor ordenado
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + menor; // ex: menor = -3, i =0 + -3 = -3 , i =2 + -3 = -1; 
            count[i]--;
        }
    }
}


int main() {
    int n;

    printf("Write the size of the array:");
    scanf(" %d", &n);

    int p[n];
    printf("Write the %d numbers within the array:", n);

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
    //!calling function 
    counting_sort(p, n);


    printf("}");
    printf("\n");
    printf("****************");
    printf("\n\n");

    // Printing after the sort
    printf("****************\n");
    printf("After the sort: {");
    for (int y = 0; y < n; y++) {
        printf("%d ", p[y]);
    }
    printf("}");
    printf("\n");
    printf("****************");
}
