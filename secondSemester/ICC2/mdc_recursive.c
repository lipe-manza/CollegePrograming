#include <stdio.h>

int mdc(int m, int n) {

    if (n == 0) {
        return m;
    }
    else {
        return mdc(n, m % n);
    }
}





int main() {

    int m, n, res;
    scanf(" %d %d", &m, &n);

    res = mdc(m, n);

    printf("o mdc entre %d e %d eh: %d", m, n, res);

    return 0;

}