#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  double a, b;
  if (argc != 4) // se for mais de 4 coisas "[0] é o .\program"
  {
    printf("Usage: prog <operando1> <operador> <operando2>\n");
    exit(1);
  }
  a = atof(argv[1]); // transformando os chars em doubles
  b = atof(argv[3]);

  switch (argv[2][0])
  {
  case '+':
    printf("%f\n", a + b);
    break;
  case '-':printf("%f", a - b);
    break;
  case '/':printf("%f", a / b);
    break;
  case '*':printf("%f", a * b);
    break;
  }


  return 0;
}
//arc counts the number of things there where inputed (1=".\nameofprogram")
//arcv is an arr of strings 
