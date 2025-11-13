#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum Metodo_ordenacao
{
    Bubble = 1,
    Selection,
    Insertion,
    Shell,
    Quick,
    Heap,
    Merge,
    Rank,
    Radix
} MET_ORD;

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    clock_t inicio = clock();
    bool trocou = true;

    for (int i = 0; i < tamanho - 1; i++)
    {
        trocou = false;
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            (*comparacoes)++;
            if (vetor[j] > vetor[j + 1])
            {
                (*movimentacoes)++;
                trocou = true;
                swap(&vetor[j], &vetor[j + 1]);
            }
        }
        if (!trocou) break;
    }

    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void selection_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    clock_t inicio = clock();

    for (int j = 0; j < tamanho - 1; j++)
    {
        int indice_menor = j;
        for (int i = j + 1; i < tamanho; i++)
        {
            (*comparacoes)++;
            if (vetor[i] < vetor[indice_menor])
            {
                indice_menor = i;
            }
        }
        if (indice_menor != j)
        {
            (*movimentacoes)++;
            int aux = vetor[j];
            vetor[j] = vetor[indice_menor];
            vetor[indice_menor] = aux;
        }
    }

    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void insertion_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    clock_t inicio = clock();

    for (int j = 1; j < tamanho; j++)
    {
        int aux = vetor[j];
        int i = j - 1;
        // desloca elementos maiores que aux
        while (i >= 0)
        {
            (*comparacoes)++;
            if (vetor[i] > aux)
            {
                (*movimentacoes)++;
                vetor[i + 1] = vetor[i];
                i--;
            }
            else break;
        }
        vetor[i + 1] = aux;
        (*movimentacoes)++;
    }

    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void shell_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    clock_t inicio = clock();

    int h = 1;

    // Calcula maior h de Knuth < n
    while (h < tamanho / 3) {
        h = 3 * h + 1;
    }

    // Aplica o Shell Sort
    while (h >= 1) {
        for (int i = h; i < tamanho; i++) {
            int temp = vetor[i];
            int j;
            for (j = i; j >= h && vetor[j - h] > temp; j -= h, (*comparacoes)++) {
                (*movimentacoes)++;
                vetor[j] = vetor[j - h];
            }
            (*movimentacoes)++;
            vetor[j] = temp;
        }
        h = h / 3; // diminui o gap
    }

    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// Substitui a implementação anterior de quick_sort por uma versão com wrapper + recursiva

// função recursiva sem medir tempo
void quick_sort_rec(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes)
{
    if (tamanho <= 1) return;

    int* fim = vetor + tamanho - 1;
    int* e = vetor;
    int* d = fim;
    int pivo = vetor[tamanho / 2];

    while (e <= d) {
        while (e <= d && *e < pivo) { (*comparacoes)++; e++; }
        while (e <= d && *d > pivo) { (*comparacoes)++; d--; }
        if (e <= d) {
            (*comparacoes)++;
            (*movimentacoes)++;
            swap(e, d);
            e++; d--;
        }
    }

    if (vetor < d) quick_sort_rec(vetor, (int)(d - vetor + 1), comparacoes, movimentacoes);
    if (e < fim) quick_sort_rec(e, (int)(fim - e + 1), comparacoes, movimentacoes);
}

// wrapper que mede o tempo
void quick_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    clock_t inicio_tempo = clock();
    quick_sort_rec(vetor, tamanho, comparacoes, movimentacoes);
    clock_t fim_tempo = clock();
    *tempo_execucao = (double)(fim_tempo - inicio_tempo) / CLOCKS_PER_SEC;
}

void heapfy(int vetor[], int tamanho, int i, long long* comparacoes, long long* movimentacoes) {
    int aux;                // variável auxiliar para trocar elementos
    int maior = i;          // assume que o nó i é o maior
    int left_child = 2 * i + 1;  // índice do filho da esquerda
    int right_child = 2 * i + 2; // índice do filho da direita

    // Verifica se o filho da esquerda é maior que o nó atual
    if (left_child < tamanho && vetor[left_child] > vetor[maior]) {
        maior = left_child;
    }

    // Verifica se o filho da direita é maior que o maior até agora
    if (right_child < tamanho && vetor[right_child] > vetor[maior]) {
        maior = right_child;
    }

    // Se o maior não for o nó atual, troca e chama recursivamente
    if (i != maior) {
        aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
        (*movimentacoes)++;

        // Chamada recursiva para garantir que o sub-heap também seja válido
        heapfy(vetor, tamanho, maior, comparacoes, movimentacoes);
    }
}
//? folhas = n/2 
//? nao_folhas = (n/2)-1

// Função que constrói o heap máximo a partir do array
void heap_construction(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes) {
    // Começa do último nó pai e vai até a raiz
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapfy(vetor, tamanho, i, comparacoes, movimentacoes); // garante a propriedade do heap para cada nó
    }
}

// Função que ordena o array usando Heap Sort
void heap_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao) {
    clock_t inicio = clock();

    heap_construction(vetor, tamanho, comparacoes, movimentacoes); // primeiro constrói o heap máximo

    // Remove o maior elemento e reorganiza o heap
    for (int i = tamanho - 1; i > 0; i--) {
        // Troca a raiz (maior) com o último elemento do heap
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        (*movimentacoes)++;

        // Heapifica a raiz para manter o heap máximo
        heapfy(vetor, i, 0, comparacoes, movimentacoes); // tamanho do heap reduzido em 1
    }

    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void merge(int* esq, int* dir, long long* comparacoes, long long* movimentacoes)
{
    int tamanho = dir - esq + 1;
    int n1 = tamanho / 2; // tamanho do subvetor esquerdo
    int n2 = tamanho - n1;     // tamanho do subvetor direito

    int v1[n1], v2[n2];   // vetores temporários

    // Copiando os elementos para os arrays temporários
    for (int i = 0; i < n1; i++) v1[i] = esq[i];
    for (int j = 0; j < n2; j++) v2[j] = esq[n1 + j];

    // Mesclando os arrays temporários de volta em esq[0..tamanho-1]
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        (*comparacoes)++;
        if (v1[i] <= v2[j]) {
            esq[k++] = v1[i++];
            (*movimentacoes)++;
        }
        else {
            esq[k++] = v2[j++];
            (*movimentacoes)++;
        }
    }

    // Copiando os elementos restantes, se houverem
    while (i < n1)
    {
        esq[k++] = v1[i++];
        (*movimentacoes)++;
    }
    while (j < n2) {
        esq[k++] = v2[j++];
        (*movimentacoes)++;
    }
}

// Função recursiva sem medir tempo
void merge_sort_rec(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes)
{
    if (tamanho <= 1) return;
    int n1 = tamanho / 2;
    int n2 = tamanho - n1;

    merge_sort_rec(vetor, n1, comparacoes, movimentacoes);
    merge_sort_rec(vetor + n1, n2, comparacoes, movimentacoes);

    // mescla as duas metades; esq aponta para início do bloco, dir para fim
    merge(vetor, vetor + tamanho - 1, comparacoes, movimentacoes);
}

// Wrapper que mede o tempo
void merge_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    clock_t inicio = clock();
    merge_sort_rec(vetor, tamanho, comparacoes, movimentacoes);
    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void rank_sort(int* vetor, int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    clock_t inicio = clock();

    int rank[tamanho];
    int aux[tamanho];

    // Inicializa os ranks
    for (int i = 0; i < tamanho; i++) {
        rank[i] = 0;
    }

    // Calcula o rank (quantos elementos são menores)
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            (*comparacoes)++;
            if (vetor[j] < vetor[i] || (vetor[j] == vetor[i] && j < i)) {
                rank[i]++;
            }
        }
    }

    // Coloca cada elemento em sua posição correta
    for (int i = 0; i < tamanho; i++) {
        aux[rank[i]] = vetor[i];
        (*movimentacoes)++;
    }

    // Copia o resultado para o vetor original
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = aux[i];
        (*movimentacoes)++;
    }

    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}


// Implementação simples de radix_sort (suporta inteiros não-negativos)
void radix_sort(int* vetor, int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao) {
    clock_t inicio = clock();
    if (tamanho <= 1) { *tempo_execucao = 0.0; return; }

    int max = vetor[0];
    for (int i = 1; i < tamanho; i++) if (vetor[i] > max) max = vetor[i];

    int* aux = (int*)malloc(tamanho * sizeof(int));
    if (!aux) { *tempo_execucao = 0.0; return; }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        int bucket[10] = { 0 };
        for (int i = 0; i < tamanho; i++) { bucket[(vetor[i] / exp) % 10]++; (*comparacoes)++; }
        for (int i = 1; i < 10; i++) bucket[i] += bucket[i - 1];
        for (int i = tamanho - 1; i >= 0; i--) {
            int idx = (vetor[i] / exp) % 10;
            aux[--bucket[idx]] = vetor[i];
            (*movimentacoes)++;
        }
        for (int i = 0; i < tamanho; i++) { vetor[i] = aux[i]; (*movimentacoes)++; }
    }

    free(aux);
    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// Função para embaralhar com índices aleatórios gerados pela get_random
void FisherYatesShuffle(int vetor[], int tamanho, int* seed)
{
    int j;

    // Embaralha o vetor
    for (int i = tamanho - 1; i >= 1; i--)
    {
        //Gera o índice aleatório
        j = get_random(seed, i) - 1;

        swap(vetor + i, vetor + j);
    }
}

int* vetor_criar(int tamanho, int estado)
{
    // Aloca memória dinamicamente para casos muito grandes não estourarem a stack
    int* vetor = (int*)malloc(tamanho * sizeof(int));

    if (vetor == NULL) return NULL;

    if (estado == 3)
        for (int i = 0; i < tamanho; i++) vetor[i] = tamanho - i;
    else
    {
        for (int i = 0; i < tamanho; i++) vetor[i] = i + 1;
        if (estado == 2)
        {
            int seed = 12345;
            FisherYatesShuffle(vetor, tamanho, &seed);
        }
    }

    return vetor;
}

// Ordena de acordo com o algoritmo desejado
void ordenar(int* vetor, int tamanho, int metodo, long long* comparacoes, long long* movimentacoes, double* tempo_execucao) {
    switch (metodo) {
    case Bubble: bubble_sort(vetor, tamanho, comparacoes, movimentacoes, tempo_execucao);
        break;
    case Selection: selection_sort(vetor, tamanho, comparacoes, movimentacoes, tempo_execucao);
        break;
    case Insertion: insertion_sort(vetor, tamanho, comparacoes, movimentacoes, tempo_execucao);
        break;
    case Shell: shell_sort(vetor, tamanho, comparacoes, movimentacoes, tempo_execucao);
        break;
    case Quick: quick_sort(vetor, tamanho, comparacoes, movimentacoes, tempo_execucao);
        break;
    case Heap: heap_sort(vetor, tamanho, comparacoes, movimentacoes, tempo_execucao);
        break;
    case Merge: merge_sort(vetor, tamanho, comparacoes, movimentacoes, tempo_execucao);
        break;
    case Rank: rank_sort(vetor, tamanho, comparacoes, movimentacoes, tempo_execucao);
        break;
    case Radix: radix_sort(vetor, tamanho, comparacoes, movimentacoes, tempo_execucao);
        break;
    default:
        printf("Método de ordenação inválido.\n");
        break;
    }
}

int main()
{
    int metodo;
    if (scanf("%d", &metodo) != 1) {
        fprintf(stderr, "Erro: entrada inválida.\n");
        return 1;
    }

    char nome_arquivo[] = "resultados/resultado_X.csv";
    // índice do 'X' na string acima é 21
    if (metodo >= 0 && metodo <= 9) nome_arquivo[21] = '0' + metodo;

    FILE* fp = fopen(nome_arquivo, "a");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    for (int tamanho = 100; tamanho <= 100000; tamanho *= 10)
    {
        for (int estado = 1; estado <= 3; estado++)
        {
            for (int rodada = 1; rodada <= 5; rodada++)
            {
                int* vetor = vetor_criar(tamanho, estado);
                if (!vetor) {
                    fprintf(stderr, "Erro ao alocar vetor tamanho %d\n", tamanho);
                    fclose(fp);
                    return 1;
                }

                long long comparacoes = 0, movimentacoes = 0;
                double tempo_execucao = 0;

                ordenar(vetor, tamanho, metodo, &comparacoes, &movimentacoes, &tempo_execucao);
                printf("Tamanho: %d, Estado: %d, Rodada: %d, Tempo: %.6lf s, Comparações: %lld, Movimentações: %lld\n",
                       tamanho, estado, rodada, tempo_execucao, comparacoes, movimentacoes);
                fprintf(fp, "%d,%d,%d,%.6lf,%lld,%lld\n", tamanho, estado, rodada, tempo_execucao, comparacoes, movimentacoes);

                free(vetor);
            }

            printf("\n");
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}
