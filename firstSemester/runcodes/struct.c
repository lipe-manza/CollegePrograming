#include <stdio.h>
struct data
{
  int dia;
  int mes;
  int ano;
};
struct hora
{
  int hora;
  int minuto;
  int segundo;
};
struct agenda
{
  struct data d;
  struct hora h;
  char nome[100];
};

void ler(int m, struct agenda *a)
{
  for (int j = 0; j < m; j++)
  {
    scanf("%d", &a[j].d.dia);
    scanf("%d", &a[j].d.mes);
    scanf("%d", &a[j].d.ano);

    scanf("%d", &a[j].h.hora);
    scanf("%d", &a[j].h.minuto);
    scanf("%d", &a[j].h.segundo);

    scanf(" %[^\n]", a[j].nome);
  }
}
void imprimir(int m, struct agenda *b)
{
  for (int i = 0; i < m; i++)
  {
    printf("%02d/%02d/%04d - %02d:%02d:%02d\n", b[i].d.dia, b[i].d.mes, b[i].d.ano, b[i].h.hora, b[i].h.minuto, b[i].h.segundo);
    if (i != m - 1)
      printf("%s\n", b[i].nome);
    else
      printf("%s", b[i].nome);
  }
}

int main()
{
  int n = 0;
  scanf("%d", &n);
  struct agenda s[n];

  ler(n, s);
  imprimir(n, s);
  
  return 0;
}
