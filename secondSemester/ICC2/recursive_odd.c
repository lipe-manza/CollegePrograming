#include <stdio.h>

int odd(int v[], int n) {
    if (n < 0) {
        return 0; // caso base: acabou o vetor
    }
    if (v[n] % 2 != 0) {
        return 1 + odd(v, n - 1);
    }
    else {
        return odd(v, n - 1);
    }
}

int main() {
    int n, quant = 0;
    printf("Choose the numbers for the array: ");
    scanf("%d", &n);

    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    quant = odd(v, n - 1); // chamar com índice máximo válido

    printf("the quantit of odd numbers is: %d\n", quant);

    return 0;
}
