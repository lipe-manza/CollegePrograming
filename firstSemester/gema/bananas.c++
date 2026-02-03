#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, k, w, total = 0;
    cin >> k >> n >> w;
    total = (k + (w * k)) * (w / 2);
    cout << total - n << endl;
    return 0;
}