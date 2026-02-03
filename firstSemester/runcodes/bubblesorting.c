#include <stdio.h>

void bubblesorting(int *arr, int m)
{
  int former = 0;
  for (int j = 0; j < m; j++)
  {
    for (int i = 0; i < m - j - 1; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        former = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = former;
      }
    }
  }
}

int main()
{
  int n = 0;
  scanf("%d", &n);
  int array[n];
  for (int k = 0; k < n; k++)
  {
    scanf("%d", array+k);
  }

  bubblesorting(array, n); // sort the array

  for (int k = 0; k < n; k++)
  {
    printf("%d ", array[k]);
  }

  return 0;
}
