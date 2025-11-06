#include <stdio.h>
#include <string.h>



void contagem_tipos(int v[], int n) {
    int i, j, maior, menor, intervalo;

    // 1️⃣ Inicializa maior e menor com o primeiro elemento
    maior = v[0];
    menor = v[0];

    // 2️⃣ Encontra o maior e menor valor no vetor
    for (int i = 0; i < n; i++) {
        if (v[i] > maior) maior = v[i];   // atualiza maior se necessário
        if (v[i] < menor) menor = v[i];   // atualiza menor se necessário
    }

    // 3️⃣ Calcula o tamanho do intervalo de valores do vetor
    // intervalo = quantidade de valores distintos possíveis entre menor e maior
    intervalo = maior - menor + 1;

    // 4️⃣ Cria um vetor auxiliar para contar a frequência de cada valor
    int aux[intervalo];
    memset(aux, 0, sizeof(int) * intervalo); // zera todas as posições

    // 5️⃣ Conta a frequência de cada valor no vetor
    for (int i = 0; i < n; i++) {
        aux[v[i] - menor]++;  // desloca o índice para começar em 0
    }

    // 6️⃣ Reconstrói o vetor ordenado
    j = 0; // índice para o vetor original
    for (int i = 0; i < intervalo; i++) {
        while (aux[i] > 0) {      // enquanto houver elementos deste valor
            v[j] = i + menor;     // coloca de volta no vetor original
            aux[i]--;             // decrementa a contagem
            j++;                  // avança para a próxima posição
        }
    }
}

int main() {
    int n;

    printf("Write the size of the array:");
    scanf(" %d", &n);

    int p[n];
    printf("Write the %d numbers within the array:", n);

    int aux;
    for (int w = 0; w < n; w++) {
        scanf(" %d", &p[w]);
    }
    printf("\n");

    // Printing before the sort
    printf("****************\n");
    printf("Before the sort: {");
    for (int z = 0; z < n; z++) {
        printf("%d ", p[z]);
    }
    //!calling function 
    contagem_tipos(p, n);


    printf("}");
    printf("\n");
    printf("****************");
    printf("\n\n");

    // Printing after the sort
    printf("****************\n");
    printf("After the sort: {");
    for (int y = 0; y < n; y++) {
        printf("%d ", p[y]);
    }
    printf("}");
    printf("\n");
    printf("****************");
}

