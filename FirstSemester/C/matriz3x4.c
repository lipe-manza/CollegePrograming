#include <stdio.h>

int main()
{
  int m[3][4], sum = 0;
  // filling the matrix
  for (int j = 0; j < 4; j++)
  {
    for (int i = 0; i < 3; i++)
    {
      scanf("%d", &m[i][j]);
    }
  }
  // sum of all elements of the matrix
  for (int j = 0; j < 4; j++)
  {
    for (int i = 0; i < 3; i++)
    {
      sum += *(*m+i);
    }
  }
  printf("sum of all the elements of the matrix: %d", sum);
  return 0;
}
