#include <stdio.h>

int fibonacci(int n)
{
  if (n == 0)
  {
    return 0;
  }
  else if (n == 1)
  {
    return 1;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
  int n = 1, ramifications = 0;
  while (n != 0)
  {
    scanf("%d", &n);
    ramifications = fibonacci(n);
    if (n == 0)
    {
      break;
    }
    else
    {
      printf("%d\n", ramifications);
    }
  }

  return 0;
}
