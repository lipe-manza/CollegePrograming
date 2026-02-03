#include <stdio.h>
#include <stdlib.h>

// Função que reorganiza o heap para garantir que o nó i seja maior que seus filhos; organiza de i até o nó mais baixo 
void heapfy(int v[], int tamanho, int i) {
    int aux;                // variável auxiliar para trocar elementos
    int maior = i;          // assume que o nó i é o maior
    int left_child = 2 * i + 1;  // índice do filho da esquerda
    int right_child = 2 * i + 2; // índice do filho da direita

    // Verifica se o filho da esquerda é maior que o nó atual
    if (left_child < tamanho && v[left_child] > v[maior]) {
        maior = left_child;
    }

    // Verifica se o filho da direita é maior que o maior até agora
    if (right_child < tamanho && v[right_child] > v[maior]) {
        maior = right_child;
    }

    // Se o maior não for o nó atual, troca e chama recursivamente
    if (i != maior) {
        aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;

        // Chamada recursiva para garantir que o sub-heap também seja válido
        heapfy(v, tamanho, maior);
    }
}
//? leafs = n/2 
//? not_leafs = (n/2)-1

// Função que constrói o heap máximo a partir do array
void heap_construction(int v[], int n) {
    // Começa do último nó pai e vai até a raiz
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapfy(v, n, i); // garante a propriedade do heap para cada nó
    }
}

// Função que ordena o array usando Heap Sort
void heap_sort(int v[], int n) {
    heap_construction(v, n); // primeiro constrói o heap máximo

    // Remove o maior elemento e reorganiza o heap
    for (int i = n - 1; i > 0; i--) {
        // Troca a raiz (maior) com o último elemento do heap
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;

        // Heapifica a raiz para manter o heap máximo
        heapfy(v, i, 0); // tamanho do heap reduzido em 1
    }
}

int main() {
    int n;
    printf("Write the size of the array: ");
    scanf(" %d", &n);

    int vector[n]; // declara o array com tamanho n

    // Lê os elementos do array
    printf("Write the %d numbers within the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &vector[i]);
    }

    // Imprime o array antes da ordenação
    printf("\n****************\n");
    printf("Before the sort: {");
    for (int z = 0; z < n; z++) {
        printf("%d ", vector[z]);
    }
    printf("}\n");
    printf("****************\n\n");

    // Ordena o array usando Heap Sort
    heap_sort(vector, n);

    // Imprime o array depois da ordenação
    printf("****************\n");
    printf("After the sort: {");
    for (int y = 0; y < n; y++) {
        printf("%d ", vector[y]);
    }
    printf("}\n");
    printf("****************\n");

    return 0;
}
