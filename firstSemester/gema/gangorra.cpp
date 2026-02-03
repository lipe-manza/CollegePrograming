#include <bits/stdc++.h>
using namespace std;
int main()
{
    int S1, C1, S2, C2;
    cin >> S1 >> C1 >> S2 >> C2;

    if (C1 < 10 || C1 > 100)
    {
        return 0;
    }
    if (S1 < 10 || S1 > 100)
    {
        return 0;
    }
    if (S2 < 10 || S2 > 100)
    {
        return 0;
    }
    if (C2 < 10 || C2 > 100)
    {
        return 0;
    }
    if (S1 * C1 == S2 * C2)
    {
        cout << "0";
    }
    else if (S1 * C1 > S2 * C2)
    {
        cout << "-1";
    }
    else
    {
        cout << "1";
    }
    return 0;
}
