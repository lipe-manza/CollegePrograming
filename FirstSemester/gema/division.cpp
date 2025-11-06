#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int arr[t];

    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }
    for (int j = 0; j < t; j++)
    {
        if (arr[j] >= 1900)
        {
            cout << "division 1 " << endl;
        }
        if (arr[j] >= 1600 && arr[j] <= 1899)
        {
            cout << "division 2 " << endl;
        }
        if (arr[j] >= 1400 && arr[j] <= 1599)
        {
            cout << "division 3 " << endl;
        }
        if (arr[j] <= 1399)
        {
            cout << "division 4 " << endl;
        }
    }
    return 0;
}
// For Division 1: 1900≤rating
// For Division 2: 1600≤rating≤1899
// For Division 3: 1400≤rating≤1599
// For Division 4: rating≤1399