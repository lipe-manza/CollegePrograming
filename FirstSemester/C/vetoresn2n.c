#include <stdio.h>

int sort(int m, int vector[m])
{
  int former;
  for (int i = 0; i < m; i++)
  {
    for (int j = 1; j < m - 1; j++)
    {
      if (vector[i] > vector[j])
      {
        former = vector[i];
        vector[i] = vector[j];
        vector[i] = former;
      }
    }
  }
  return vector[m];
}

int main()
{
  int n, p = 0, r = 0, x = 0;
  scanf("%d", &n);
  int v1[n], v2[n], v3[2 * n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &v1[i]);
  }
  for (int j = 0; j < n; j++)
  {
    scanf("%d", &v2[j]);
  }

  sort(n, v1);
  sort(n, v2);

  for (x = 0; x < 2 * n; x++)
  {
    if (p == n || r == n)
    {
      break;
    }
    if (v1[p] < v2[r])
    {
      v3[x] = v1[p++];
    }
    else
    {
      v3[x] = v2[r++];
    }
  }

  while (p < n)
  {
    v3[x] = v1[p++];
  }
  while (r < n)
  {
    v3[x] = v2[r++];
  }
  for (int g = 0; g < 2 * n; g++)
  {
    printf("%d", v3[g]);
  }
}
