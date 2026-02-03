#include <stdio.h>
#define n 31
int main()
{

  int v[n], former = 0, pos = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &v[i]);
  }
  for (int i = n - 2; i >= 0; i--)
  {
    if (v[n - 1] < v[i])
    {
      former = v[n - 1];
      v[n - 1] = v[i];
      v[i] = former;
      pos = i + 1;
    }
  }
  if (pos == 0)
  {
    pos = 31;
  }
  printf("%d\n", v[n - 1]);
  for (int t = 0; t < n - 1; t++)
  {
    if (v[n - 1] == v[t])
    {
      printf("%d\n", t + 1);
    }
  }
  printf("%d ", pos);
  return 0;
}
