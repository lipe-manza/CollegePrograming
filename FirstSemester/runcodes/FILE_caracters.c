#include <stdio.h>

int main()
{
  char arquive_name[10], ch;
  int count = 0;
  scanf("%s", arquive_name);

  FILE *fp = fopen(arquive_name, "r");

  do
  {
    count++;
    ch = getc(fp);
  } while (ch != EOF);

  printf("%d", count - 1);

  return 0;
}
