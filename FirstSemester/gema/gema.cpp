#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;

    if (x == 1)
    {
        cout << "x não é primo";
    }
    else{
        int flag=0;
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0 )
        {
           flag=1;
        }
        
    }
    if(flag=1){
        cout<< "o número não é primo";
    }
    else{

        cout<<"o número é primo";
    }

    return 0;
}
}