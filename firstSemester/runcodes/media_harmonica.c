#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int readInt()
{
  int m = 0;
  scanf(" %d", &m);
  return m;
}

double readDouble()
{
  double grade = 0.0;
  scanf("%lf", &grade);
  return grade;
}

void printDouble(double valor)
{
  printf("%.2lf", valor);
}

int main()
{

  int n = readInt();
  double notas[n], media, sumdenominador = 0;
  for (int i = 0; i < n; i++)
  {
    notas[i] = readDouble();
  }
  for (int j = 0; j < n; j++)
  {
    sumdenominador += 1 / (notas[j] + 1);
  }

  media = (n / sumdenominador) - 1;

  printDouble(media);
  return 0;
}
