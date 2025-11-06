#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char **s1;
  // alocação
  s1 = (char **)malloc(sizeof(char *) * 3);
  for (int i = 0; i < 3; i++)
  {
    s1[i] = (char *)malloc(sizeof(char) * 10001);
  }

  // leitura
  for (int i = 0; i < 2; i++)
  {
    scanf(" %10000[^\n]", s1[i]);
  }

  // usar para comparação
  int n1 = strlen(s1[0]);
  int n2 = strlen(s1[1]);
  int j = 0;
  int maior = 0;

  for (int k = 0; k < n2; k++)
  {
    int tamanho = n2 - j;
    int limite = n1 - tamanho;
    if (limite < 0)
      limite = -1;
    for (int i = 0; i <= limite; i++)
    {
      if (memcmp(s1[0] + i, s1[1], tamanho) == 0)
      {
        memcpy(s1[2], s1[0] + i, tamanho);
        s1[2][tamanho] = '\0';
        maior = tamanho;
        break;
      }
    }
    j++;
    if (maior > 0)
      break;
  }

  printf("%d %s", maior, s1[2]);

  // free nos allocs
  for (int i = 0; i < 3; i++)
  {
    free(s1[i]);
  }
  free(s1);
  return 0;
}
