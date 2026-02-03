#include <bits/stdc++.h>
using namespace std;
int troca(int i)
{
    return (i == 0) ? 1 : 0;
}

int main()
{

    int Ia, Ib, Fa, Fb, n = 0;

    cin >> Ia >> Ib >> Fa >> Fb;

    while (Ia != Fa || Ib != Fb)
    {
        if (Ib != Fb)
        {
            n += 1;
            Ib=troca(Ib);
            Ia=troca(Ia);
        }

        if (Ia != Fa)
        {
            n += 1;
            Ia=troca(Ia);
        }
    } 
    cout<< n <<endl;

    return 0;
}