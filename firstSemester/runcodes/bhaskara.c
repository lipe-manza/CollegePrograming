#include <stdio.h>
#include <math.h>
int main(){

int a , b , c, delta ;
double x1 , x2;

scanf("%d %d %d", &a , &b , &c);


delta=b*b-(4*a*c);

if(delta<0){
printf("NAO EXISTE RAIZ REAL");
}else if(delta==0){
    x1=(double)(-b)/(2*a);
    printf("%.3lf", x1);
}else{

    x1=(-b + sqrt(delta))/(2*a);
    x2=(-b - sqrt(delta))/(2*a);
printf("%.3lf %.3lf", x2 , x1);
}

return 0;




}