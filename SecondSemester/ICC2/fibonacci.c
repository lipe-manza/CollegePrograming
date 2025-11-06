#include <stdio.h>


int fibonacci(int n) {
    printf(" %d\n", n);
    return n < 2 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {


    int res = fibonacci(50);
    printf(" %d", res);
    return 0;
}