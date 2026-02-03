#include <stdio.h>
#include <string.h>
void imprimir(int m, char matriz[m][100])
{

  for (int i = 0; i < m; i++)
  {
    printf("%s\n", matriz[i]);
  }
}
int main()
{
  int n, b;
  scanf("%d %d", &n, &b);
  char musicas[n][100];

  for (int i = 0; i < n; i++)
  {
    scanf(" %[^\n]", musicas[i]);
  }

  switch (b)
  {
  case 1:
    for (int k = 0; k < n; k++)
    {
      for (int i = 0; musicas[k][i] != '\0'; i++)
      {

        for (char j = 'A'; j <= 'Z'; j++)
        {
          if (j == musicas[k][i] - 32)
          {
            musicas[k][i] = j;
          }
        }
      }
    }
    break;
  case 0:
    for (int k = 0; k < n; k++)
    {
      for (int i = 0; musicas[k][i] != '\0'; i++)
      {

        for (char j = 'a'; j <= 'z'; j++)
        {
          if (j == musicas[k][i] + 32)
          {
            musicas[k][i] = j;
          }
        }
      }
    }
    break;
  }

  imprimir(n, musicas);
  return 0;
}

// 65-90 maiusculas
// 97-122 minusculas
