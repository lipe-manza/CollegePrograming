#include <stdio.h>

int main()
{
  int vector[10], greater; // greater: the greater number of the vector

  scanf("%d", &vector[0]);
  greater = vector[0];

  for (int i = 0; i < 9; i++)
  {
    scanf("%d", &vector[i]);
    if (vector[i] > greater) // if the next number put on the vector, greater recive the number
    {
      greater = vector[i];
    }
  }

  printf("%d", greater);
  return 0;
}
