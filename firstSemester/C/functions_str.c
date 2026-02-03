#include <stdio.h>

void print(char str[])//ou *str
{

  printf("%c", str[5]);

}
int sum(int a, int b)
{
  return a + b;
}
double cubo()
{
  int c;
  scanf("%d", &c);
  return (c * c * c);
}
int main()
{
  char mensage[101];
  scanf("%[^\n]", mensage);
  print(mensage);

  return 0;
}
