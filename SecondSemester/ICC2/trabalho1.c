// Enzo Trulenque Evangelista - 15819219
// Luiz Felipe Manzoli Franceschini - 16913300

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define a estrutura do item com peso e valor
typedef struct item ITEM;

struct item {
    int peso; // peso do item
    int valor; // valor do item
};

// calcula a densidade de um item (valor dividido pelo peso)
double densidade(ITEM* item)
{
    return (double)item->valor / item->peso;
}

// troca dois inteiros (usado para trocar indices)
void trocar(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// retorna o maior entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// ordena os itens por densidade em ordem decrescente usando quicksort
void quicksort(ITEM itens[], int pos[], int inicio, int fim) {
    if (inicio >= fim) return;

    int pivo = pos[(inicio + fim) / 2]; // escolhe o pivo
    double d_pivo = densidade(&itens[pivo]); // densidade do pivo

    int i = inicio, j = fim;
    while (i <= j) {
        // encontra elementos fora de ordem
        while (densidade(&itens[pos[i]]) > d_pivo) i++;
        while (densidade(&itens[pos[j]]) < d_pivo) j--;
        if (i <= j) {
            trocar(&pos[i], &pos[j]); // troca os indices
            i++;
            j--;
        }
    }

    // ordena as duas metades
    if (inicio < j) quicksort(itens, pos, inicio, j);
    if (i < fim) quicksort(itens, pos, i, fim);
}

// resolve o problema da mochila usando forca bruta
int forca_bruta(ITEM itens[], int n, int W, int res[]) {
    int total = 1 << n; // numero total de subconjuntos (2^n)
    int max_mask = 0; // mascara do subconjunto com maior valor
    int max_peso = 0; // peso do subconjunto com maior valor
    int max_valor = 0; // valor do subconjunto com maior valor

    for (int mask = 0; mask < total; mask++) {
        int valor_total = 0; // valor total do subconjunto atual
        int peso_total = 0; // peso total do subconjunto atual
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { // verifica se o item i esta no subconjunto
                valor_total += itens[i].valor;
                peso_total += itens[i].peso;
                if (peso_total > W) { // se ultrapassar o peso maximo, ignora
                    break;
                }
            }
        }
        // atualiza o melhor subconjunto encontrado
        if (peso_total <= W) {
            if (valor_total > max_valor) {
                max_mask = mask;
                max_valor = valor_total;
                max_peso = peso_total;
            }
            else if (valor_total == max_valor) {
                if (peso_total < max_peso) {
                    max_mask = mask;
                    max_valor = valor_total;
                    max_peso = peso_total;
                }
            }
        }
    }

    // armazena os indices dos itens escolhidos
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (max_mask & (1 << i)) { // verifica se o item i esta no subconjunto
            res[count++] = i;
        }
    }

    return count; // retorna o numero de itens escolhidos
}

// resolve o problema da mochila usando algoritmo guloso
int guloso(ITEM itens[], int pos[], int W, int res[], int n)
{
    quicksort(itens, pos, 0, n - 1); // ordena os itens por densidade

    int peso_restante = W; // capacidade restante da mochila

    int tam = 0; // quantidade de itens escolhidos

    for (int i = 0; i < n; i++)
    {
        if (itens[pos[i]].peso <= peso_restante) // verifica se o item cabe na mochila
        {
            res[tam++] = pos[i]; // adiciona o item ao resultado
            peso_restante -= itens[pos[i]].peso; // atualiza o peso restante
        }
    }

    return tam; // retorna o numero de itens escolhidos
}

// resolve o problema da mochila usando programacao dinamica
int prog_din(ITEM itens[], int  n, int W, int res[]) {
    int dp[n + 1][W + 1]; // tabela para armazenar os resultados intermediarios
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = 0; // inicializa a tabela com zero
        }
    }

    // preenche a tabela dp
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (itens[i - 1].peso <= j) { // verifica se o item cabe na mochila
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - itens[i - 1].peso] + itens[i - 1].valor);
            }
            else {
                dp[i][j] = dp[i - 1][j]; // nao inclui o item
            }
        }
    }
    // recupera os itens escolhidos
    int k = W;
    int count = 0;
    for (int i = n; i > 0;i--) {
        if (dp[i][k] != dp[i - 1][k]) { // verifica se o item foi incluido
            res[count++] = i - 1;  // armazena o indice do item
            k -= itens[i - 1].peso;  // diminui a capacidade restante
        }
    }

    // inverte os itens para manter a ordem original
    for (int i = 0; i < count / 2; i++) {
        int tmp = res[i];
        res[i] = res[count - i - 1];
        res[count - i - 1] = tmp;
    }
    return count; // retorna o numero de itens escolhidos
}

int main() {
    int n = 0, ope = 0, W = 0, tam = 0;
    printf("********************************************************************************\n");
    printf("*                     PROBLEMA DA MOCHILA 0/1                                  *\n");
    printf("********************************************************************************\n");
    printf("Escolha a operacao desejada:\n");
    printf("  1 = Forca Bruta\n");
    printf("  2 = Algoritmo Guloso\n");
    printf("  3 = Arogramacao Dinamica\n");
    printf("opcao: ");
    scanf(" %d", &ope);

    printf("\ninforme o numero de itens: ");
    scanf(" %d", &n);

    printf("informe o peso maximo da mochila: ");
    scanf(" %d", &W);

    ITEM itens[n];
    int pos[n];

    printf("\ninsira os itens no formato (peso valor):\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("item %d: ", i);
        scanf(" %d %d", &itens[i].peso, &itens[i].valor);
        pos[i] = i; // inicializa os indices
    }
    int res[n];

    // escolhe o algoritmo com base na opcao do usuario
    switch (ope) {
    case 1: tam = forca_bruta(itens, n, W, res); break;
    case 2: tam = guloso(itens, pos, W, res, n); break;
    case 3: tam = prog_din(itens, n, W, res); break;
    default:
        printf("\nopcao invalida!\n");
        return 1;
    }

    printf("\n******************************* resultado *******************************\n");
    printf("itens escolhidos (indices): ");
    for (int i = 0; i < tam; i++) {
        printf("%d", res[i]);
        if (i != tam - 1) printf(", ");
    }
    printf("\n");

    int total_valor = 0, total_peso = 0;
    for (int i = 0; i < tam; i++) {
        total_valor += itens[res[i]].valor; // soma os valores dos itens escolhidos
        total_peso += itens[res[i]].peso; // soma os pesos dos itens escolhidos
    }

    printf("peso total da mochila: %d\n", total_peso);
    printf("valor total da mochila: %d\n", total_valor);
    printf("**************************************************************************\n");

    return 0;
}





