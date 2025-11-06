#include <stdio.h>

int main()
{

  int n, count = 0, countpar = 0, countletras = 0, countimpar = 0;
  scanf("%d", &n);
  char livro[n + 1];
  scanf("%s", livro);

  for (char j = 'a'; j <= 'z'; j++)
  {
    count = 0;
    for (int i = 0; i < n; i++)
    {
      if (livro[i] == j)
      {
        count++;
      }
    }
    if (count > 0)
    {
      countletras++;
    }
    if (count % 2 == 0 && count != 0)
    {
      countpar++;
    }
    else if (count % 2 == 1 && count != 0)
    {
      countimpar++;
    }
  }

  if (((countpar == (countletras - 1)) && countimpar == 1) || (countpar == countletras))
  {
    printf("Sim");
  }
  else
  {
    printf("Nao");
  }
  return 0;
}
