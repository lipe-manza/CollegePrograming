#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
  int x, y;

} ponto_t;

int main()
{

  char arquive_name[10];

  scanf(" %[^n]", arquive_name);

  FILE *fp;
  fp=fopen(arquive_name, "r+");
  ponto_t st[10];

  while (!feof(fp))
  {
    fread()
  }
}
