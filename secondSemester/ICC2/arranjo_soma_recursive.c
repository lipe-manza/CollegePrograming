#include <stdio.h>

int sum(int n, int v[]) {
    return n == 1 ? v[0] : v[n - 1] + sum(n - 1, v);

}


int main() {
    int n = 0, res = 0;
    printf("digite o tamanho do arranjo: ");
    scanf("%d", &n);

    int v[n];
    res = sum(n, v);

}