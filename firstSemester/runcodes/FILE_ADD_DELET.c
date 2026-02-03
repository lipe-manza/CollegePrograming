#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[50];
  char phone[12];
  char city[50];
} data_t;

int main()
{
  int lines_of_file = 0, line_to_delete = 0;
  char file_name[50], command[10];

  int capacity = 100;
  data_t *r = malloc(capacity * sizeof(data_t));

  // Lê o nome do arquivo
  scanf("%s", file_name);

  // Abre o arquivo para leitura
  FILE *fp = fopen(file_name, "r");
  if (fp == NULL)
  {
    printf("Error opening file.\n");
    free(r);
    return 1;
  }

  // Lê os dados do arquivo original
  while (fscanf(fp, " %49[^,] , %11[^,] , %49[^\n]",
                r[lines_of_file].name,
                r[lines_of_file].phone,
                r[lines_of_file].city) == 3)
  {
    lines_of_file++;
  }

  fclose(fp);

  //
  while (scanf("%s", command) != EOF)
  {
    if (strcmp(command, "ADD") == 0)
    {

      scanf(" %49[^,], %11[^,], %49[^\n]",
            r[lines_of_file].name,
            r[lines_of_file].phone,
            r[lines_of_file].city);
      lines_of_file++;
    }
    else if (strcmp(command, "DEL") == 0 || strcmp(command, "DELETE") == 0)
    {
      scanf("%d", &line_to_delete);
      if (line_to_delete >= 0 && line_to_delete < lines_of_file)
      {
        for (int i = line_to_delete; i < lines_of_file - 1; i++)
        {
          r[i] = r[i + 1];
        }
        lines_of_file--;
      }
    }
  }

  // Reabre o arquivo no modo escrita para salvar as alterações e ainda abre ele
  fp = fopen(file_name, "w");
  if (fp == NULL)
  {
    printf("Error opening file.\n");
    free(r);
    return 1;
  }
// printa no arquivo
  for (int i = 0; i < lines_of_file; i++)
  {
    fprintf(fp, "%s, %s, %s\n", r[i].name, r[i].phone, r[i].city);
  }
  
  for (int i = 0; i < lines_of_file; i++)
  {
    printf("%s, %s, %s\n", r[i].name, r[i].phone, r[i].city);
  }

  fclose(fp);
  free(r);

  return 0;
}
