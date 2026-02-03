#include <stdio.h>


int fatorial(int n) {
    return n == 0 ? 1 : n * fatorial(n - 1);
}

int main() {

    int n = 0;

    printf("escolha o numero fatorial: ");
    scanf(" %d", &n);

    int res = fatorial(n);
    printf("%d", res);
    return 0;
}