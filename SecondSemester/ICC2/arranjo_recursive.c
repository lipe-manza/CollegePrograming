#include <stdio.h>


int greater(int n, int temp) {
    int maior;
    scanf(" %d", &maior);
    if (maior >= temp && n != 1) {
        return greater(--n, maior);
    }
    else if (temp >= maior && n != 1) {
        return greater(--n, temp);
    }
    else {
        return maior >= temp ? maior : temp;
    }


}
int main() {
    int n = 0;
    printf("digite n: ");
    scanf(" %d", &n);

    int maior = 0;
    printf("digite os numeros do arranjo: ");

    maior = greater(n, maior);
    printf("%d ", maior);
    return 0;


}