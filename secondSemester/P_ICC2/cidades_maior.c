#include <stdio.h>
#include <string.h>

typedef struct city {
    char name[1000];
    int population;
}stru;



int main() {

    int n;

    scanf(" %d", &n);
    if (n < 2 || n>10) {//verificação de erro
        printf("n fora do intervalo.");
        return 0;
    }

    stru cities[n];
    int maior = 0, lugarMaior = 0;


    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", cities[i].name);
        scanf(" %d", &cities[i].population);
        if (maior <= cities[i].population) {
            lugarMaior = i;
            maior = cities[i].population;
        }
    }


    printf("%s ", cities[lugarMaior].name);
    printf("%d", cities[lugarMaior].population);



    return 0;




}