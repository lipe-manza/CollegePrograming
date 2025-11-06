#include <stdio.h>
#include <stdlib.h>
void counting_sort_digit(int arr[], int n, int exp) {
    int output[n];
    int count[10] = { 0 };

    // Conta ocorrências dos dígitos
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Acumula contagem
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Preenche output de trás pra frente (estável)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copia de volta
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int max_array(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}


void radix_sort_positive(int arr[], int n) {
    int max = max_array(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        counting_sort_digit(arr, n, exp);
}


void radix_sort(int arr[], int n) {

    // Conta quantos negativos há
    int negCount = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] < 0) negCount++;

    // Separa negativos e positivos
    int neg[negCount];
    int pos[n - negCount];

    int iNeg = 0, iPos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) neg[iNeg++] = -arr[i]; // Inverte sinal
        else pos[iPos++] = arr[i];
    }

    // Ordena positivos
    if (iPos > 0)
        radix_sort_positive(pos, iPos);

    // Ordena negativos (como positivos)
    if (iNeg > 0) {
        radix_sort_positive(neg, iNeg);
        // Reverte sinal novamente
        for (int i = 0; i < iNeg; i++)
            neg[i] = -neg[i];
    }

    // Junta: negativos primeiro, depois positivos
    // Mas negativos agora estão em ordem crescente (ex: -9, -2, -1)
    // Porém nos arrays normais eles ficaram descendentes antes,
    // então precisamos inverter:
    for (int i = 0; i < iNeg; i++)
        arr[i] = neg[iNeg - 1 - i];

    for (int i = 0; i < iPos; i++)
        arr[iNeg + i] = pos[i];
}

int main() {
    int n;
    printf("Size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Numbers: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nBefore: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    radix_sort(arr, n);

    printf("\nAfter:  ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
