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

void swap(int* a, int* b, long long* movimentacoes)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    (*movimentacoes)++;
}

void bubble_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    // Incia a cronometragem do algoritmo
    clock_t inicio = clock();

    // Flag para verificar se houve troca, otimizando o algoritmo
    bool trocou = true;

    for (int i = 0; i < tamanho - 1; i++)
    {
        // Reseta a flag no início de cada passagem
        trocou = false;
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            (*comparacoes)++; // incrementa o contador de comparações
            if (vetor[j] > vetor[j + 1])
            {
                // Atualiza a flag se houve troca
                trocou = true;
                // Realiza a troca 
                swap(&vetor[j], &vetor[j + 1], movimentacoes);
            }
        }
        // Se não houve troca, o vetor já está ordenado e sai do loop
        if (!trocou) break;
    }

    // Finaliza a cronometragem do algoritmo
    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void selection_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    // Inicia a cronometragem do algoritmo
    clock_t inicio = clock();

    for (int j = 0; j < tamanho - 1; j++)
    {
        // Encontra o índice do menor elemento no subarray não ordenado
        int indice_menor = j;
        for (int i = j + 1; i < tamanho; i++)
        {
            // Compara e atualiza o índice do menor elemento
            (*comparacoes)++;
            if (vetor[i] < vetor[indice_menor])
            {
                // Atualiza o índice do menor elemento
                indice_menor = i;
            }
        }
        if (indice_menor != j)
            // Troca o menor elemento encontrado com o primeiro elemento do subarray não ordenado
            swap(&vetor[j], &vetor[indice_menor], movimentacoes);
    }

    // Finaliza a cronometragem do algoritmo
    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void insertion_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    // Inicia a cronometragem do algoritmo
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
                // Move o elemento para a direita
                vetor[i + 1] = vetor[i];
                // Move para o próximo elemento à esquerda
                i--;
            }
            else break;
        }
        // Insere o elemento na posição correta
        vetor[i + 1] = aux;
        (*movimentacoes)++;
    }
    // Finaliza a cronometragem do algoritmo
    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void shell_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    // Inicia a cronometragem do algoritmo
    clock_t inicio = clock();

    int h = 1;

    // Calcula maior h de Knuth < n
    while (h < tamanho / 3) {
        h = 3 * h + 1;
    }

    // Aplica o Shell Sort
    while (h >= 1) {
        for (int i = h; i < tamanho; i++) {
            // Temp armazena o valor a ser inserido
            int temp = vetor[i];
            int j;
            for (j = i; j >= h; j -= h) {
                (*comparacoes)++; // Contar comparação
                if (vetor[j - h] > temp) {
                    // Desloca o elemento para a direita
                    vetor[j] = vetor[j - h];
                    (*movimentacoes)++;
                }
                // Se não for maior, sai do loop interno
                else {
                    break;
                }
            }
            // Insere o valor na posição correta
            vetor[j] = temp;
            (*movimentacoes)++;
        }
        // Reduz o gap
        h = h / 3;
    }

    // Finaliza a cronometragem do algoritmo
    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// Mediana de três: Apenas ordena os 3 pontos para garantir bons sentinelas
int mediana_de_tres(int* vetor, int esq, int dir, long long* comparacoes, long long* movimentacoes) {
    int meio = esq + (dir - esq) / 2;

    comparacoes += 3; // Três comparações serão feitas abaixo

    // Ordena os três valores
    if (vetor[esq] > vetor[meio])swap(&vetor[esq], &vetor[meio], movimentacoes);
    if (vetor[esq] > vetor[dir])  swap(&vetor[esq], &vetor[dir], movimentacoes);
    if (vetor[meio] > vetor[dir]) swap(&vetor[meio], &vetor[dir], movimentacoes);

    return vetor[meio];
}

void quick_sort_rec(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes) {
    // Caso base
    if (tamanho <= 1) return;

    int pivo = mediana_de_tres(vetor, 0, tamanho - 1, comparacoes, movimentacoes);

    // Configuração dos ponteiros (partição de Hoare)
    // Devido à Mediana de 3, sabemos que vetor[0] < pivo e vetor[tam-1] > pivo.
    // Podemos pular o primeiro e o último elemento com segurança.
    int* inicio_ptr = vetor;
    int* fim_ptr = vetor + tamanho - 1;

    int* e = inicio_ptr + 1; // Avança 1 pois vetor[0] já é menor/igual
    int* d = fim_ptr - 1;    // Recua 1 pois vetor[tam-1] já é maior/igual

    while (e <= d) {
        // Não precisamos verificar limites (e <= fim_ptr) porque o mediana_de_tres
        // colocou sentinelas (valores maiores/menores) nas pontas.
        while (*e < pivo) {
            (*comparacoes)++;
            e++;
        }

        while (*d > pivo) {
            (*comparacoes)++;
            d--;
        }
        // Contabiliza a comparação de saída dos loops (quando a condição falha)
        (*comparacoes) += 2;

        if (e <= d) {
            swap(e, d, movimentacoes);
            e++;
            d--;
        }
    }

    // Recursão
    // Calcula o tamanho dos subvetores com base na posição dos ponteiros
    if (vetor < d) quick_sort_rec(vetor, (int)(d - vetor + 1), comparacoes, movimentacoes);
    if (e < fim_ptr) quick_sort_rec(e, (int)(fim_ptr - e + 1), comparacoes, movimentacoes);
}

void quick_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    clock_t inicio_tempo = clock();

    // Inicializa contadores caso venham com lixo de memória
    *comparacoes = 0;
    *movimentacoes = 0;

    quick_sort_rec(vetor, tamanho, comparacoes, movimentacoes);

    // Finaliza a cronometragem do algoritmo
    clock_t fim_tempo = clock();
    *tempo_execucao = (double)(fim_tempo - inicio_tempo) / CLOCKS_PER_SEC;
}

void heapify(int vetor[], int tamanho, int i, long long* comparacoes, long long* movimentacoes) {
    int maior = i;          // assume que o nó i é o maior
    int left_child = 2 * i + 1;  // índice do filho da esquerda
    int right_child = 2 * i + 2; // índice do filho da direita

    // Contar comparação do filho esquerdo
    if (left_child < tamanho) {
        (*comparacoes)++;
        if (vetor[left_child] > vetor[maior]) {
            maior = left_child;
        }
    }

    // Contar comparação do filho direito
    if (right_child < tamanho) {
        (*comparacoes)++;
        if (vetor[right_child] > vetor[maior]) {
            maior = right_child;
        }
    }

    // Contar comparação se houve troca
    if (i != maior) {
        // Troca o nó atual com o maior filho
        swap(&vetor[i], &vetor[maior], movimentacoes);
        // Chamada recursiva para garantir a propriedade do heap
        heapify(vetor, tamanho, maior, comparacoes, movimentacoes);
    }
}

// Função que constrói o heap máximo a partir do array
void heap_construction(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes) {
    // Começa do último nó pai e vai até a raiz
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        // Garante a propriedade do heap para cada nó
        heapify(vetor, tamanho, i, comparacoes, movimentacoes);
    }
}

// Função que ordena o array usando Heap Sort
void heap_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao) {
    // Inicia a cronometragem do algoritmo
    clock_t inicio = clock();

    heap_construction(vetor, tamanho, comparacoes, movimentacoes); // primeiro constrói o heap máximo

    // Remove o maior elemento e reorganiza o heap
    for (int i = tamanho - 1; i > 0; i--) {
        // Troca a raiz (maior) com o último elemento do heap
        swap(&vetor[0], &vetor[i], movimentacoes);

        // Heapifica a raiz para manter o heap máximo
        heapify(vetor, i, 0, comparacoes, movimentacoes); // tamanho do heap reduzido em 1
    }

    // Finaliza a cronometragem do algoritmo
    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// Função que mescla usando um vetor auxiliar pré-alocado
void merge(int* vetor, int* aux, int esq, int meio, int dir, long long* comparacoes, long long* movimentacoes)
{
    // Copia os elementos do vetor original para o auxiliar
    // Otimização: fazemos a cópia completa do bloco primeiro
    for (int i = esq; i <= dir; i++) {
        aux[i] = vetor[i];
        (*movimentacoes)++;
    }

    int i = esq;      // Índice do início da sub-lista esquerda no aux
    int j = meio + 1; // Índice do início da sub-lista direita no aux
    int k = esq;      // Índice do vetor original (onde vamos gravar)

    // Intercalação: devolve do aux para o vetor original de forma ordenada
    while (i <= meio && j <= dir) {
        (*comparacoes)++;
        if (aux[i] <= aux[j]) {
            vetor[k++] = aux[i++];
        }
        else {
            vetor[k++] = aux[j++];
        }
        (*movimentacoes)++;
    }

    // Copia os elementos restantes da metade esquerda (se houver)
    // Nota: Não é preciso copiar a metade direita, pois se ela sobrar,
    // já está na posição correta no vetor original.
    while (i <= meio) {
        vetor[k++] = aux[i++];
        (*movimentacoes)++;
    }
}

// Função recursiva com índices e vetor auxiliar
void merge_sort_rec(int* vetor, int* aux, int esq, int dir, long long* comparacoes, long long* movimentacoes)
{
    if (esq >= dir) return;

    int meio = esq + (dir - esq) / 2;

    // Ordena primeira metade
    merge_sort_rec(vetor, aux, esq, meio, comparacoes, movimentacoes);
    // Ordena segunda metade
    merge_sort_rec(vetor, aux, meio + 1, dir, comparacoes, movimentacoes);

    // Intercala as duas metades
    merge(vetor, aux, esq, meio, dir, comparacoes, movimentacoes);
}

// Função principal
void merge_sort(int vetor[], int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    clock_t inicio = clock();

    int* aux = (int*)malloc(tamanho * sizeof(int));

    if (aux != NULL) {
        // Chama a função recursiva passando o buffer auxiliar
        merge_sort_rec(vetor, aux, 0, tamanho - 1, comparacoes, movimentacoes);

        // Libera a memória uma única vez ao final
        free(aux);
    }
    else {
        printf("Erro: Falha ao alocar memória auxiliar.\n");
    }

    // Finaliza a cronometragem do algoritmo
    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// Implementação do Rank Sort
void rank_sort(int* vetor, int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao)
{
    // Inicia a cronometragem do algoritmo
    clock_t inicio = clock();

    // Vetores auxiliares
    int* rank = (int*)malloc(tamanho * sizeof(int)), * aux = (int*)malloc(tamanho * sizeof(int));

    // Inicializa os ranks
    for (int i = 0; i < tamanho; i++) {
        rank[i] = 0;
    }

    // Calcula o rank (quantos elementos são menores)
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            // duas comparações por iteração
            (*comparacoes) += 2;
            if (vetor[j] < vetor[i] || (vetor[j] == vetor[i] && j < i)) {
                // Incrementa o rank se encontrar um elemento menor ou igual com índice menor
                rank[i]++;
            }
        }
    }

    // Coloca cada elemento em sua posição correta
    for (int i = 0; i < tamanho; i++) {
        // Coloca o elemento na posição indicada pelo seu rank
        aux[rank[i]] = vetor[i];
        (*movimentacoes)++;
    }

    // Copia o resultado para o vetor original
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = aux[i];
        (*movimentacoes)++;
    }

    free(rank);
    free(aux);

    // Finaliza a cronometragem do algoritmo
    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}


// Implementação simples de radix_sort (suporta inteiros não-negativos)
void radix_sort(int* vetor, int tamanho, long long* comparacoes, long long* movimentacoes, double* tempo_execucao) {
    // Inicia a cronometragem do algoritmo
    clock_t inicio = clock();
    if (tamanho <= 1) { *tempo_execucao = 0.0; return; }

    // Encontra o valor máximo para determinar o número de dígitos
    int max = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > max) max = vetor[i];
        (*comparacoes)++; // <-- corrigido
    }

    // Aloca o array auxiliar
    int* aux = (int*)malloc(tamanho * sizeof(int));
    if (!aux) { *tempo_execucao = 0.0; return; }

    // Realiza a ordenação por cada dígito
    for (int exp = 1; max / exp > 0; exp *= 10) {
        // Inicializa o bucket/
        int bucket[10] = { 0 };
        // Conta a ocorrência de cada dígito
        for (int i = 0; i < tamanho; i++) {
            bucket[(vetor[i] / exp) % 10]++; (*comparacoes)++;
        }
        // Atualiza os buckets para posições
        for (int i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }
        // Constrói o array ordenado com base no dígito atual
        for (int i = tamanho - 1; i >= 0; i--) {
            // Variável idx para armazenar o dígito atual
            int idx = (vetor[i] / exp) % 10;
            // Coloca o elemento na posição correta no array auxiliar                                   
            aux[--bucket[idx]] = vetor[i];
            (*movimentacoes)++;
        }
        // Copia o array auxiliar de volta para o array original
        for (int i = 0; i < tamanho; i++) {
            vetor[i] = aux[i]; (*movimentacoes)++;
        }
    }

    // Libera o array auxiliar
    free(aux);

    // Finaliza a cronometragem do algoritmo
    clock_t fim = clock();
    *tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// Função para embaralhar com índices aleatórios gerados pela get_random
void FisherYatesShuffle(int vetor[], int tamanho)
{
    long long _ = 0; // contador de movimentações temporário
    // Embaralha o vetor
    for (int i = tamanho - 1; i >= 1; i--)
    {
        int j = rand() % (i + 1); // índice aleatório entre 0 e i

        swap(&vetor[i], &vetor[j], &_); // movimentações contadas em _
    }
}

int* vetor_criar(int tamanho, int estado, int seed)
{
    // Aloca memória dinamicamente para casos muito grandes não estourarem a stack
    int* vetor = (int*)malloc(tamanho * sizeof(int));

    if (vetor == NULL) return NULL;

    // Preenche o vetor de acordo com o estado desejado
    if (estado == 3)
        // Vetor em ordem decrescente
        for (int i = 0; i < tamanho; i++) vetor[i] = tamanho - i;
    else
    {
        // Vetor em ordem crescente
        for (int i = 0; i < tamanho; i++) vetor[i] = i + 1;
        // Se o estado for 2, embaralha o vetor
        if (estado == 2)
        {
            srand(seed);  // inicializa o gerador
            
            FisherYatesShuffle(vetor, tamanho);
            // usa a semente passada para variar entre as rodadas
        }
    }

    return vetor;
}

// Ordena de acordo com o algoritmo desejado
void ordenar(int* vetor, int tamanho, int metodo, long long* comparacoes, long long* movimentacoes, double* tempo_execucao) {
    // Chama a função de ordenação correspondente ao método escolhido
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
        // Método inválido
        printf("Método de ordenação inválido.\n");
        break;
    }
}

int main()
{
    // Lê o método de ordenação a ser utilizado
    int metodo;
    if (scanf("%d", &metodo) != 1) {
        fprintf(stderr, "Erro: entrada inválida.\n");
        return 1;
    }

    // Prepara o arquivo de saída
    char nome_arquivo[] = "resultados/resultado_X.csv";
    // índice do 'X' na string acima é 21
    if (metodo >= 0 && metodo <= 9) nome_arquivo[21] = '0' + metodo;

    // Abre o arquivo para escrita
    FILE* fp = fopen(nome_arquivo, "a");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    // Escreve o cabeçalho do CSV
    fprintf(fp, "tamanho,estado,rodada,tempo_execucao,comparacoes,movimentacoes\n");

    // Loop pelos tamanhos, estados e rodadas
    for (int tamanho = 100; tamanho <= 100000; tamanho *= 10)
    {
        // Três estados: 1 - ordenado, 2 - aleatório, 3 - reverso
        for (int estado = 1; estado <= 3; estado++)
        {
            // Cinco rodadas para cada configuração
            for (int rodada = 1; rodada <= 5; rodada++)
            {
                // Cria o vetor conforme o tamanho e estado (agora com seed)
                int* vetor = vetor_criar(tamanho, estado, rodada);
                if (!vetor) {
                    fprintf(stderr, "Erro ao alocar vetor tamanho %d\n", tamanho);
                    fclose(fp);
                    return 1;
                }
                // Variáveis para armazenar métricas
                long long comparacoes = 0, movimentacoes = 0;
                double tempo_execucao = 0;

                // Ordena o vetor e mede as métricas
                ordenar(vetor, tamanho, metodo, &comparacoes, &movimentacoes, &tempo_execucao);

                // Imprime os resultados no console
                printf("Tamanho: %d, Estado: %d, Rodada: %d, Tempo: %.6lf s, Comparações: %lld, Movimentações: %lld\n", tamanho, estado, rodada, tempo_execucao, comparacoes, movimentacoes);
                // Escreve os resultados no arquivo CSV
                fprintf(fp, "%d,%d,%d,%.6lf,%lld,%lld\n", tamanho, estado, rodada, tempo_execucao, comparacoes, movimentacoes);

                // Libera a memória alocada para o vetor
                free(vetor);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Fecha o arquivo e encerra o programa
    fclose(fp);
    return 0;
}