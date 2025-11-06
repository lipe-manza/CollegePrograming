#include <stdio.h>
#include <stdlib.h>

void mult(int l1, int k1, int k2, int **ma1, int **ma2, int **ma3)
{
  for (int j = 0; j < l1; j++)
  {
    for (int i = 0; i < k2; i++)
    {
      ma3[j][i] = 0;
      for (int h = 0; h < k1; h++)
      {
        ma3[j][i] += ma1[j][h] * ma2[h][i];
      }
    }
  }
}

int main()
{
  int n1, t1, n2, t2;

  printf("escolha o valor das linhas e colunas da 1matriz:");
  scanf("%d %d", &n1, &t1);
  printf("escolha o valor das linhas e colunas da 2matriz:");
  scanf("%d %d", &n2, &t2);

  if (t1 != n2)
  {
    printf("não é possivel multiplicar\n");
    return 0;
  }

  int **m1;
  int **m2;
  int **m3;
  m1 = (int **)malloc(sizeof(int *) * n1);
  m2 = (int **)malloc(sizeof(int *) * n2);
  m3 = (int **)malloc(sizeof(int *) * n1);

  for (int i = 0; i < n1; i++)
  {
    m1[i] = (int *)malloc(sizeof(int) * t1);
  }
  for (int i = 0; i < n2; i++)
  {
    m2[i] = (int *)malloc(sizeof(int) * t2);
  }
  for (int i = 0; i < n1; i++)
  {
    m3[i] = (int *)malloc(sizeof(int) * t2);
  }

  printf("escolha os valores da 1matriz %dx%d:\n", n1, t1);
  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < t1; j++)
    {
      scanf("%d", &m1[i][j]);
    }
  }

  printf("escolha os valores da 2matriz %dx%d:\n", n2, t2);
  for (int i = 0; i < n2; i++)
  {
    for (int j = 0; j < t2; j++)
    {
      scanf("%d", &m2[i][j]);
    }
  }

  mult(n1, t1, t2, m1, m2, m3);

  printf("\nMatriz 1:\n");
  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < t1; j++)
    {
      printf("%d ", m1[i][j]);
    }
    printf("\n");
    free(m1[i]);
  }

  printf("\nMatriz 2:\n");
  for (int i = 0; i < n2; i++)
  {
    for (int j = 0; j < t2; j++)
    {
      printf("%d ", m2[i][j]);
    }
    printf("\n");
    free(m2[i]);
  }

  printf("\nMatriz Resultado (m3):\n");
  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < t2; j++)
    {
      printf("%d ", m3[i][j]);
    }
    printf("\n");
    free(m3[i]);
  }

  free(m1);
  free(m2);
  free(m3);
  return 0;
}
