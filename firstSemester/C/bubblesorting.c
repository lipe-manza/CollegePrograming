#include <stdio.h>

int main()
{

  int vector[10], x = 0, former;

  for (int i = 0; i < 10; i++)
  {
    scanf("%d", vector + i);
  }

  for (x = 0; x < 10; x++)
  {
    for (int y = 0; y < 10 - x - 1; y++)
    {
      if (vector[y] > vector[y + 1])
      {
        former = vector[y];
        vector[y] = vector[y + 1];
        vector[y]= former;
      }
    }
    for (int t = 0; t < 10; t++)
    {
      printf("%d ", vector[t]);
    }

    return 0;
  }
}
