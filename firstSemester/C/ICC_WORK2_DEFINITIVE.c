#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_REGISTROS 1000
#define EPS 0.001

typedef struct
{
  int id;
  char login[16];
  char password[31];
  char gender;
  double salary;
  int ocupado;
} User;

User *banco[MAX_REGISTROS] = {NULL};

void carregar_json(const char *nomeArquivo, int *total)
{
  FILE *fp = fopen(nomeArquivo, "r");
  if (!fp)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  char linha[256];
  User temp;
  int lendo = 0;
  int i = 0;

  while (fgets(linha, sizeof(linha), fp))
  {
    if (strchr(linha, '{'))
    {
      memset(&temp, 0, sizeof(User));
      temp.gender = ' ';
      lendo = 1;
      continue;
    }

    if (!lendo)
      continue;

    if (strchr(linha, '}'))
    {
      if (i < MAX_REGISTROS)
      {
        banco[i] = malloc(sizeof(User));
        *banco[i] = temp;
        banco[i]->ocupado = 1;
        (*total)++;
        i++;
      }
      lendo = 0;
      continue;
    }

    sscanf(linha, " \"id\" : %d", &temp.id);
    sscanf(linha, " \"login\" : \"%[^\"]", temp.login);
    sscanf(linha, " \"password\" : \"%[^\"]", temp.password);
    sscanf(linha, " \"gender\" : \"%c\"", &temp.gender);
    sscanf(linha, " \"salary\" : %lf", &temp.salary);
  }

  fclose(fp);
  printf("%d registro(s) lido(s).\n", *total);
}

int verificar(User *r, const char *campo, const char *valor)
{
  if (strcmp(campo, "id") == 0)
  {
    return r->id == atoi(valor);
  }
  else if (strcmp(campo, "login") == 0)
  {
    return strcmp(r->login, valor) == 0;
  }
  else if (strcmp(campo, "password") == 0)
  {
    return strcmp(r->password, valor) == 0;
  }
  else if (strcmp(campo, "gender") == 0)
  {
    if (strlen(valor) == 0)
      return r->gender == ' ' || r->gender == '\0';
    return r->gender == valor[0];
  }
  else if (strcmp(campo, "salary") == 0)
  {
    return fabs(r->salary - atof(valor)) < EPS;
  }
  return 0;
}

void imprimir(User *r)
{
  printf("{\n");
  printf("    \"id\": %d,\n", r->id);
  printf("    \"login\": \"%s\",\n", r->login);
  printf("    \"password\": \"%s\",\n", r->password);
  if (r->gender == ' ' || r->gender == '\0')
    printf("    \"gender\": \"\",\n");
  else
    printf("    \"gender\": \"%c\",\n", r->gender);
  printf("    \"salary\": %.2lf\n", r->salary);
  printf("}\n");
}

void inserir(int id, char *login, char *password, char gender, double salary)
{
  for (int i = 0; i < MAX_REGISTROS; i++)
  {
    if (!banco[i] || banco[i]->ocupado == 0)
    {
      if (!banco[i])
        banco[i] = malloc(sizeof(User));
      banco[i]->id = id;
      strncpy(banco[i]->login, login, 15);
      banco[i]->login[15] = '\0';
      strncpy(banco[i]->password, password, 30);
      banco[i]->password[30] = '\0';
      banco[i]->gender = gender;
      banco[i]->salary = salary;
      banco[i]->ocupado = 1;
      printf("Registro inserido.\n");
      return;
    }
  }

  printf("Sem espaço para inserção.\n");
}

void buscar(const char *campo, const char *valor)
{
  int achou = 0;
  for (int i = 0; i < MAX_REGISTROS; i++)
  {
    if (banco[i] && banco[i]->ocupado && verificar(banco[i], campo, valor))
    {
      imprimir(banco[i]);
      achou = 1;
    }
  }
  if (!achou)
    printf("Nada encontrado.\n");
}

void remover(const char *campo, const char *valor)
{
  if (strlen(campo) == 0)
  {
    printf("Remoção inválida.\n");
    return;
  }

  int removidos = 0;
  for (int i = 0; i < MAX_REGISTROS; i++)
  {
    if (banco[i] && banco[i]->ocupado && verificar(banco[i], campo, valor))
    {
      banco[i]->ocupado = 0;
      removidos++;
    }
  }
  if (removidos)
    printf("%d registro(s) removido(s).\n", removidos);
  else
    printf("Remoção inválida.\n");
}

void tirar_aspas(char *str)
{
  size_t len = strlen(str);
  if (len >= 2 && str[0] == '"' && str[len - 1] == '"')
  {
    memmove(str, str + 1, len - 2);
    str[len - 2] = '\0';
  }
}

int main()
{
  char nomeArquivo[100];
  scanf("%s", nomeArquivo);
  int total = 0;
  carregar_json(nomeArquivo, &total);
  getchar();

  char linha[256];
  while (fgets(linha, sizeof(linha), stdin))
  {
    int comando;
    sscanf(linha, "%d", &comando);

    if (comando == 1)
    {
      int id;
      char login[50], password[50], g[5];
      double salario;
      sscanf(linha, "1 %d \"%[^\"]\" \"%[^\"]\" \"%[^\"]\" %lf", &id, login, password, g, &salario);
      inserir(id, login, password, g[0], salario);
    }
    else if (comando == 2 || comando == 3)
    {
      char campo[50], valor[100] = "";
      sscanf(linha, "%*d \"%[^\"]\" %[^\n]", campo, valor);
      tirar_aspas(valor);
      if (comando == 2)
        buscar(campo, valor);
      else
        remover(campo, valor);
    }
  }

  for (int i = 0; i < MAX_REGISTROS; i++)
  {
    if (banco[i])
      free(banco[i]);
  }

  return 0;
}
