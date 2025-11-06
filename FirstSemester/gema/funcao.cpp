#include <bits/stdc++.h>
using namespace std;

int main(){
int n, soma=0;
cin>> n;

int funcao[n];

for(int i=0 ; i<n ;i++){

if(i%2==0 || i==0){

    funcao[i]=-(i+1);
}else{
    funcao[i]=(i+1);
}

soma= soma + funcao[i];
}

cout<< soma;
return 0;
}