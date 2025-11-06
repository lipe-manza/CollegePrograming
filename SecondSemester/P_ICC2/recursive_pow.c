#include <stdio.h>
#include <math.h>
#include <time.h>

int potencia(int n, int k) {
    int aux;
    if (n == 1 || k == 0) {
        return 1;
    }
    else if (k == 1) {
        return (n % 1000);
    }
    else if (k % 2 == 1) {
        aux = (potencia((n % 1000), k / 2)) % 1000;
        return  (((n % 1000) * aux * aux)) % 1000;
    }
    else {
        aux = (potencia((n % 1000), k / 2)) % 1000;
        return  ((aux * aux)) % 1000;
    }

}

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    printf("%d", potencia(n, k) % 1000);

    return 0;
}