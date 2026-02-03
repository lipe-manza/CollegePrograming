#include <stdio.h>
#include <stdlib.h>
int swt(int *ptr1, int *ptr2)
{
  int former = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = former;
}
int main()
{


  int *p1 = (int *)malloc(sizeof(int));

  int *p2 = (int *)malloc(sizeof(int));
  scanf("%d", p1);
  scanf("%d", p2);


  printf("%d %d\n", *p1, *p2);
  swt(p1, p2);
  printf("%d %d", *p1, *p2);
free(p1);
free(p2);
  return 0;
}
