#include <bits/stdc++.h>
using namespace std;
int main(){

int A,M;

if(A<1 || A>50 || M<1 || M>50){

    return 0;
}

if(A+M>50){
    cout<<"N";
}else{
    cout<<"S";
}
return 0;
}
