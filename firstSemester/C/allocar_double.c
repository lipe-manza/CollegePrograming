#include <stdio.h>
#include <stdlib.h>

double *alocar(int n)
{

  double *p1 = (double *)malloc(n * sizeof(double));
  return p1;
}
int main()
{
  int tamanho = 0;

  printf("esolha o tamanho do vetor : ");
  scanf("%d", &tamanho);
  double *p;

  p = alocar(tamanho);

  for (int i = 0; i < tamanho; i++)
  {
    printf("%d° valor: ", i);
    scanf("%lf", &p[i]);
  }
  printf("valores obtidos:\n");
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d° valor: %lf\n", i ,p[i]);

  }

  free(p);
  return 0;
}

