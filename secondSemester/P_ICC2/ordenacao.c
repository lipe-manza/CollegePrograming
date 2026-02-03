#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char cor[10];
  double comprimento;
  double nota;
  int indice_original;
} Brinquedo;

// Função de comparação que implementa os critérios de ordenação
int comparar(Brinquedo* a, Brinquedo* b) {
  // 1º critério: cor (ordem alfabética)
  int cmp_cor = strcmp(a->cor, b->cor);
  if (cmp_cor != 0) return cmp_cor;

  // 2º critério: comprimento (menor primeiro)
  if (a->comprimento < b->comprimento) return -1;
  if (a->comprimento > b->comprimento) return 1;

  // 3º critério: nota (maior primeiro, por isso invertido)
  if (a->nota > b->nota) return -1;
  if (a->nota < b->nota) return 1;

  // Estabilidade: preservar ordem original em caso de empate
  return a->indice_original - b->indice_original;
}

// Bubble Sort
void bubble_sort(Brinquedo* arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (comparar(&arr[j], &arr[j + 1]) > 0) {
        Brinquedo temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Insertion Sort
void insertion_sort(Brinquedo* arr, int n) {
  for (int i = 1; i < n; i++) {
    Brinquedo chave = arr[i];
    int j = i - 1;

    while (j >= 0 && comparar(&arr[j], &chave) > 0) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = chave;
  }
}

// Merge Sort - Função auxiliar para merge
void merge(Brinquedo* arr, int esq, int meio, int dir) {
  int n1 = meio - esq + 1;
  int n2 = dir - meio;

  Brinquedo* L = (Brinquedo*)malloc(n1 * sizeof(Brinquedo));
  Brinquedo* R = (Brinquedo*)malloc(n2 * sizeof(Brinquedo));

  for (int i = 0; i < n1; i++)
    L[i] = arr[esq + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[meio + 1 + j];

  int i = 0, j = 0, k = esq;

  while (i < n1 && j < n2) {
    if (comparar(&L[i], &R[j]) <= 0) {
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

  free(L);
  free(R);
}

// Merge Sort - Função recursiva
void merge_sort_rec(Brinquedo* arr, int esq, int dir) {
  if (esq < dir) {
    int meio = esq + (dir - esq) / 2;
    merge_sort_rec(arr, esq, meio);
    merge_sort_rec(arr, meio + 1, dir);
    merge(arr, esq, meio, dir);
  }
}

void merge_sort(Brinquedo* arr, int n) {
  merge_sort_rec(arr, 0, n - 1);
}

// Quick Sort - Função de particionamento
int particionar(Brinquedo* arr, int baixo, int alto) {
  Brinquedo pivo = arr[alto];
  int i = baixo - 1;

  for (int j = baixo; j < alto; j++) {
    if (comparar(&arr[j], &pivo) <= 0) {
      i++;
      Brinquedo temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  Brinquedo temp = arr[i + 1];
  arr[i + 1] = arr[alto];
  arr[alto] = temp;

  return i + 1;
}

// Quick Sort - Função recursiva
void quick_sort_rec(Brinquedo* arr, int baixo, int alto) {
  if (baixo < alto) {
    int pi = particionar(arr, baixo, alto);
    quick_sort_rec(arr, baixo, pi - 1);
    quick_sort_rec(arr, pi + 1, alto);
  }
}

void quick_sort(Brinquedo* arr, int n) {
  quick_sort_rec(arr, 0, n - 1);
}

int main() {
  int n, metodo;

  scanf("%d", &n);

  Brinquedo* brinquedos = (Brinquedo*)malloc(n * sizeof(Brinquedo));

  // Leitura dos brinquedos
  for (int i = 0; i < n; i++) {
    scanf("%s %lf %lf", brinquedos[i].cor,
      &brinquedos[i].comprimento,
      &brinquedos[i].nota);
    brinquedos[i].indice_original = i;
  }

  scanf("%d", &metodo);

  // Escolha do algoritmo de ordenação
  switch (metodo) {
  case 1:
    bubble_sort(brinquedos, n);
    break;
  case 2:
    insertion_sort(brinquedos, n);
    break;
  case 3:
    merge_sort(brinquedos, n);
    break;
  case 4:
    quick_sort(brinquedos, n);
    break;
  }

  // Impressão dos índices ordenados
  for (int i = 0; i < n; i++) {
    printf("%d;", brinquedos[i].indice_original);
  }
  printf("\n");

  free(brinquedos);

  return 0;
}