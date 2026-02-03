#include <stdio.h>

typedef struct
{
  char street[50];
  int number;
  char neighborhood[50];
  char zip_code[10];
  char city[50];

} s_endereço; 

typedef struct
{
  int num;
  char name[50];
  int pwd;
  int age;
  float salary;
  s_endereço *endereço;

} cadastro;

int main()
{
}
