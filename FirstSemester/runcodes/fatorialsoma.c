  #include <stdio.h>

  int main()
  {
    int n;
    double s = 1, fatorial=1;
    scanf("%d", &n);

    for (int i = 0; i < n-1 ; i++)
    {
      fatorial*= (i+2);
      if (i % 2 == 0)
      {
        s += 1/fatorial;
      }
      else
      {
        s += (-1) * (1/fatorial);
      }
    }
    printf("%lf", s);
    return 0;
  }
