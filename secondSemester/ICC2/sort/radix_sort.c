#include <stdio.h>
#include <string.h>

// Counting sort aplicado a um dígito específico (exp = 1, 10, 100 ...)
void counting_sort_digit(int arr[], int n, int exp) {
    int output[n];
    int count[10] = { 0 };

    // Conta ocorrências do dígito
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Torna count cumulativo
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
 
    // Constrói array ordenado para este dígito
    // (de trás pra frente para manter estabilidade)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copia de volta para arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int max_array(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

// so para positivos
void radix_sort(int arr[], int n) {
    // Descobre o maior número
    int max = max_array(arr, n);
    // Faz counting sort para cada dígito (exp = 1 → unidades, 10 → dezenas ...)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort_digit(arr, n, exp);
    }
}


int main() {
    int n;
    printf("Size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nBefore: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    radix_sort(arr, n);

    printf("\nAfter:  ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
