#include <stdio.h>
#include <stdlib.h>

int *alocar(int n)
{
  int *p;
  p = (int *)calloc(n, sizeof(int));// aloca um pedaço de memória na heap e não vai serdesalocada enquanto não fizer free, portanto mesmo que *p dessa função seja desalocado a heap não vai ser
  return p;
}
int main()
{ 
  int n, *p;

  scanf("%d", &n);

  p = alocar(n);

  p[0] = 3;

  free(p);

  return EXIT_SUCCESS;
}
