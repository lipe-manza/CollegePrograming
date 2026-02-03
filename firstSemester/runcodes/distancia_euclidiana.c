#include <stdio.h>
#include <math.h>

int main()
{
  int n = 0;
  scanf("%d", &n);
  double x[n], y[n], distance = 0.0;

  for (int i = 0; i < n; i++)
  {
    scanf("%lf %lf", &x[i], &y[i]);
  }

  for (int j = 0; j < n - 1; j++)
  {
    distance += sqrt(((x[j] - x[j + 1]) * (x[j] - x[j + 1])) + ((y[j] - y[j + 1]) * (y[j] - y[j + 1])));
  }

  printf("%.4lf", distance);

  return 0;
}
