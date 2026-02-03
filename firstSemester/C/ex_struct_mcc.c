#include <stdio.h>

typedef struct dados
{
  char name[50];
  char adress[100];
  char phone[12];
} dados_t;

typedef struct
{
  int numerator;
  int denominator;

} fraction;

int main()
{
  fraction d1, d2;

  scanf("%d %d %d %d", &d1.numerator, &d1.denominator, &d2.numerator, &d2.denominator);
  int a = 0;
  int b = 0;
  int i = 2;
  a = (d1.numerator * d2.denominator) + (d2.numerator * d1.denominator);
  b = d1.denominator * d2.denominator;

  int higher = (a > b) ? a : b;

  if (a % b == 0)
  {
    printf("%d", a / b);
  }
  else
  {
    while (i <= higher)
    {
      while (a % i == 0 && b % i == 0)
      {
        a = a / i;
        b = b / i;
      }
      i++;
    }
    printf("%d/%d", a, b);
  }

  return 0;
}
