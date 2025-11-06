#include <stdio.h>

int main()
{
  int questions = 0, students = 0, count = 0;
  scanf("%d%d", &questions, &students);
  double notas[students];
  char gabarito[students + 1][questions];

  //preenche a matriz 
  for (int j = 0; j < students + 1; j++)
  {
    for (int i = 0; i < questions; i++)
    {
      scanf(" %c", &gabarito[j][i]);
    }
  }

  for (int j = 1; j < students + 1; j++)
  {
    notas[count]=0.0;
    for (int i = 0; i < questions; i++)
    {
      if (gabarito[j][i] == gabarito[0][i])
      {
        notas[count] += 10.00;
      }
      else
      {
        notas[count] += 0.00;
      }
    }
    count++;
  }
  for (int i = 0; i < students; i++)
  {
    printf("%.2lf\n", notas[i] / questions);
  }

  return 0;
}
