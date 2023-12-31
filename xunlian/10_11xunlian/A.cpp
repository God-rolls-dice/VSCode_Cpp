#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    int tp = n % 5;
    if (tp < 5 - tp)
    {
        cout << n / 5 * 5;
    }
    else
    {
        cout << n / 5 * 5 + 5;
    }
}

signed main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}