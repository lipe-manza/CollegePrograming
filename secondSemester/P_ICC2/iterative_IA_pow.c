#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int result = 1;
    n = n % 1000;  // Mantemos apenas os 3 últimos dígitos de n

    // Algoritmo iterativo de exponenciação modular
    while (k > 0) {
        if (k % 2 == 1) {
            result = (result * n) % 1000;
        }
        n = (n * n) % 1000;
        k /= 2;
    }

    // Formata a saída com 3 dígitos (com zeros à esquerda se necessário)
    printf("%d\n", result);
    return 0;
}