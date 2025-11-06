#include <stdio.h>
#include <stdlib.h>

struct cadastro
{
  char nome[100];
  int numero;
  char assunto[100];
};

void fill(int t, int insc, struct cadastro *p)
{
  for (int i = 0 + t; i < insc; i++)
  {
    scanf(" %[^\n]", p[i].nome);
    scanf("%d", &p[i].numero);
    scanf(" %[^\n]", p[i].assunto);
  }
}
void imprimir(int insc, struct cadastro *a)
{
  for (int i = 0; i < insc; i++)
  {
    printf("Discente %d:\n", i + 1);
    printf("Nome: %s\n", a[i].nome);
    printf("Número USP: %d\n", a[i].numero);
    printf("Assunto: %s\n\n", a[i].assunto);
  }
}

int main()
{
  int n = 0, m = 0, temp = 0;
  scanf("%d", &n);

  int inscricoes = n;

  struct cadastro *c = malloc(inscricoes * sizeof(struct cadastro));
  // cadastro
  fill(temp, inscricoes, c);

  temp = inscricoes;
  // novas inscricoes
  scanf("%d", &m);
  inscricoes += m;
  // realocando o espaço
  c = realloc(c, inscricoes * sizeof(struct cadastro));

  fill(temp, inscricoes, c);

  imprimir(inscricoes, c);

  free(c);

  return 0;
}
