#include <stdio.h>
#include <math.h>

int potencia(int n, int k) {
    int aux = 1;

    if (n == 1 || k == 0) {
        return 1;
    }
    else if (k == 1) {
        return (n % 1000);
    }
    for (int i = 0; i < k; i++) {

        aux = (aux * n) % 1000;
    }

    return (aux);
}


int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    printf("%d", potencia(n, k));

    return 0;
}