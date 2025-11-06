#include <stdio.h>
#include <string.h>

int function(int inicio, int fim, char nomes[][51], char alvo[])
{
  if (inicio > fim)
  {
    return -1;
  }
  int meio = (inicio + fim) / 2;
  int comp = strcmp(nomes[meio], alvo);
  if (comp == 0)
  {
    return meio;
  }
  else if (comp > 0)
  {
    return function(inicio, meio - 1, nomes, alvo);
  }
  else
  {
    return function(meio + 1, fim, nomes, alvo);
  }
  return -1;
}

int main()
{
  int n = 0;
  scanf("%d", &n);
  char nomes[n][51];
  char alvo[50];

  for (int i = 0; i < n; i++)
  {

    scanf(" %[^\n]", nomes[i]);
  }

  scanf(" %[^\n]", alvo);

  int resultado = function(0, n - 1, nomes, alvo);

  if (resultado != -1)
  {
    printf("Jogo encontrado na posição %d", resultado);
  }
  else
  {
    printf("Jogo nao encontrado");
  }

  return 0;
}
