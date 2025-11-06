#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define limite 1000

typedef struct
{
  int id;
  char login[16];
  char password[31];
  char gender;
  double salary;
  int ocupado;
} data;

data *banco[limite] = {NULL};

void carregar_json(const char *arquive_name, int *quantidade)
{
  FILE *arquive = fopen(arquive_name, "r");
  if (arquive == NULL)
  {
    printf("Erro ao abrir o arquivo %s.\n", arquive_name);
    exit(1);
  }

  char linha[256];
  data temp;
  int i = 0;
  int dentro_arquive = 0;

  while (fgets(linha, sizeof(linha), arquive) && i < limite)
  {
    if (strstr(linha, "{"))
    {
      memset(&temp, 0, sizeof(data));
      temp.gender = ' ';
      dentro_arquive = 1;
    }
    else if (dentro_arquive && strstr(linha, "\"id\""))
    {
      sscanf(linha, " %*[^:]: %d", &temp.id);
    }
    else if (dentro_arquive && strstr(linha, "\"login\""))
    {
      char buffer[50];
      sscanf(linha, " %*[^:]: \"%[^\"]", buffer);
      strncpy(temp.login, buffer, 15);
      temp.login[15] = '\0';
    }
    else if (dentro_arquive && strstr(linha, "\"password\""))
    {
      char buffer[50];
      sscanf(linha, " %*[^:]: \"%[^\"]", buffer);
      strncpy(temp.password, buffer, 30);
      temp.password[30] = '\0';
    }
    else if (dentro_arquive && strstr(linha, "\"gender\""))
    {
      char buffer[5] = "";
      sscanf(linha, " %*[^:]: \"%[^\"]", buffer);
      if (strlen(buffer) > 0)
        temp.gender = buffer[0];
    }
    else if (dentro_arquive && strstr(linha, "\"salary\""))
    {
      sscanf(linha, " %*[^:]: %lf", &temp.salary);
    }
    else if (dentro_arquive && strstr(linha, "}"))
    {
      banco[i] = malloc(sizeof(data));
      temp.ocupado = 1;
      *banco[i] = temp;
      i++;
      dentro_arquive = 0;
    }
  }

  fclose(arquive);
  *quantidade = i;
  printf("%d registro(s) lido(s).\n", i);
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

int verificar(data *r, const char *tipo_do_dado, const char *valor_do_dado)
{
  if (strcmp(tipo_do_dado, "id") == 0)
  {
    return r->id == atoi(valor_do_dado);
  }
  else if (strcmp(tipo_do_dado, "login") == 0)
  {
    return strcmp(r->login, valor_do_dado) == 0;
  }
  else if (strcmp(tipo_do_dado, "password") == 0)
  {
    return strcmp(r->password, valor_do_dado) == 0;
  }
  else if (strcmp(tipo_do_dado, "gender") == 0)
  {
    if (strlen(valor_do_dado) == 0)
    {
      return (r->gender == ' ' || r->gender == '\0');
    }
    return r->gender == valor_do_dado[0];
  }
  else if (strcmp(tipo_do_dado, "salary") == 0)
  {
    double diff = fabs(r->salary - atof(valor_do_dado));
    return diff < 0.001;
  }
  return 0;
}

void inserir(int id, char *login, char *password, char gender, double salary)
{
  int quantidade_inserido = 0;
  for (int i = 0; i < limite; i++)
  {
    if (banco[i] == NULL || banco[i]->ocupado == 0)
    {
      if (banco[i] == NULL)
      {
        banco[i] = malloc(sizeof(data));
      }
      banco[i]->id = id;
      strncpy(banco[i]->login, login, 15);
      banco[i]->login[15] = '\0';
      strncpy(banco[i]->password, password, 30);
      banco[i]->password[30] = '\0';
      banco[i]->gender = gender;
      banco[i]->salary = salary;
      banco[i]->ocupado = 1;
      printf("Registro inserido.\n");
      quantidade_inserido = 1;
      return;
    }
  }
  if (quantidade_inserido == 0)
  {
    printf("Sem espaço para inserção.\n");
  }
}

void print(data *r)
{
  printf("{\n");
  printf("    \"id\": %d,\n", r->id);
  printf("    \"login\": \"%s\",\n", r->login);
  printf("    \"password\": \"%s\",\n", r->password);
  if (r->gender == ' ' || r->gender == '\0')
  {
    printf("    \"gender\": \"\",\n");
  }
  else
  {
    printf("    \"gender\": \"%c\",\n", r->gender);
  }
  printf("    \"salary\": %.2f\n", r->salary);
  printf("}\n");
}

void remover(char *tipo_do_dado, char *valor_do_dado)
{ // Funçao responsavel por remover o usuario que foi ordenado
  int removidos = 0;
  for (int i = 0; i < limite; i++)
  {
    if (banco[i] && banco[i]->ocupado && verificar(banco[i], tipo_do_dado, valor_do_dado))
    {
      banco[i]->ocupado = 0;
      removidos++;
    }
  }
  if (removidos > 0)
  {
    printf("%d registro(s) removido(s).\n", removidos);
  }
  else
  {
    printf("Remoção inválida.\n");
  }
}

void buscar(char *tipo_do_dado, char *valor_do_dado)
{
  int encontrado = 0;
  for (int i = 0; i < limite; i++)
  {
    if (banco[i] && banco[i]->ocupado && verificar(banco[i], tipo_do_dado, valor_do_dado))
    {
      print(banco[i]);
      encontrado = 1;
    }
  }
  if (encontrado == 0)
  {
    printf("Nada encontrado.\n");
  }
}

int main()
{
  char arquive_name[100];
  scanf("%s", arquive_name);
  int quantidade = 0;
  carregar_json(arquive_name, &quantidade);

  char linha_command[256];
  getchar();

  while (fgets(linha_command, sizeof(linha_command), stdin))
  {
    int command;
    sscanf(linha_command, "%d", &command);

    if (command == 1)
    {
      int id;
      char login[50], password[50], str[50];
      double salario;
      sscanf(linha_command, "1 %d \"%[^\"]\" \"%[^\"]\" \"%[^\"]\" %lf", &id, login, password, str, &salario);
      inserir(id, login, password, str[0], salario);
    }
    else if (command == 2 || command == 3)
    {
      char tipo_do_dado[20], valor_do_dado[100] = "";
      sscanf(linha_command, "%*d \"%[^\"]\" %[^\n]", tipo_do_dado, valor_do_dado);
      tirar_aspas(valor_do_dado);
      if (command == 2)
      {
        buscar(tipo_do_dado, valor_do_dado);
      }
      else
      {
        remover(tipo_do_dado, valor_do_dado);
      }
    }
  }

  for (int i = 0; i < limite; i++)
  {
    if (banco[i] != NULL)
    {
      free(banco[i]);
    }
  }
}
