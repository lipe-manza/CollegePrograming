#include <stdio.h>

int main(){

int a, b , c ;

scanf("%d \n %d \n %d\n ", &a,&b , &c);

if(a>b && a>c){
    printf("%d", a);
    
}
if(b>a && b>c){
    printf("%d", b);

}
if(c>b && c>a){
    printf("%d", c);

}
return 0;
}