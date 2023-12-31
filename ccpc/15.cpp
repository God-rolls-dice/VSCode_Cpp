#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n = 0;
    cin >> n;
    cout << 3 << endl;
    if (n == 1)
    {
        cout << 2 << ' ' << 1 << ' ' << 0;
    }
    else if (n == 2)
    {
        cout << 1 << ' ' << 2 << ' ' << 0 << endl;
        cout << 2 << ' ' << 0 << ' ' << 2 << endl;
    }
    else
    {
        int x = (1 + n - 2) * (n - 2) / 2 + 1;
        for (int i = 1; i < n - 1; i++)
        {
            cout << i << ' ' << 0 << ' ' << 2 * i << endl;
        }
        cout << x << ' ' << 2 * x - 1 << ' ' << 0 << endl;
        cout << 1 << ' ' << 0 << ' ' << 1 << endl;
    }
}