#include <stdio.h>
int main(){
double a, b,c ,d, media;
scanf("%lf %lf %lf %lf", &a, &b ,&c ,&d);

if(a<=b && a<=c && a<=d){

    media=(b+c+d)/3;
}if(b<=a && b<=c && b<=d){

    media=(a+c+d)/3;

}if(c<=b && c<=a && c<=d){

    media=(a+b+d)/3;

}if(d<=b && d<=c && d<=a){

    media=(a+b+c)/3;
}
printf("%.4lf", media);
return 0;

}