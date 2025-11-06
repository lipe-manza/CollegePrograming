#include <stdio.h>

int binary_search(int arr[], int inicio, int fim, int key) {
  if (inicio > fim) return -1;
  int meio = (inicio + fim) / 2;

  if (arr[meio] == key) return meio;


  return (arr[meio] > key) ? binary_search(arr, inicio, meio - 1, key) : binary_search(arr, meio + 1, fim, key);


}

int binary_search_n_rec(int arr[], int inicio, int fim, int key) {
  while (inicio <= fim) {
    int meio = (inicio + fim) / 2;
    if (arr[meio] == key) return meio;
    else if (arr[meio] < key) {
      inicio = meio + 1;
    }
    else {
      fim = meio - 1;
    }
  }
  return -1;
}


int main() {

  int n;
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int key;
  scanf("%d", &key);

  int index = binary_search_n_rec(arr, 0, n - 1, key);

  printf("%d", index);
  return 0;

}
