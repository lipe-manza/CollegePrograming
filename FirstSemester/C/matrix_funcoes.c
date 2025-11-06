#include <stdio.h>


void scan(int v, int b, double m[v][b])
{
  for (int j = 0; j < b; j++)
  {
    for (int i = 0; i < v; i++)
    {
      scanf("%lf", &m[i][j]);
    }
  }

}

double sum(int v, int b, double m[v][b])
{
  double s = 0;
  for (int j = 0; j < b; j++)
  {
    for (int i = 0; i < v; i++)
    {
      s += m[j][i];
    }
  }
  return s;
}

void print(double soma)
{
  printf("%lf", soma);
}

int main()
{

  int m = 0, n = 0;
  scanf("%d %d", &m, &n);
  double matrix[m][n], soma = 0;

  scan(m, n, matrix);
  soma = sum(m, n, matrix);
  print(soma);
  return 0;
}
