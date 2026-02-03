#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t, a, b, c;
    cin >> t;
    char arr[t];
    for (int i = 0; i < t; i++)
    {

        cin >> a >> b >> c;
        if (a + b == c)
        {
            arr[i] = '+';
        }

        if (a - b == c)
        {
            arr[i] = '-';
        }
    }
    for (int j = 0; j < t; j++)
    {

        cout << arr[j] << endl;
    }
    return 0;
}