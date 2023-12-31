#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int c = a * b / __gcd(a, b);
    int aa = n / a, bb = n / b, cc = n / c;
    int an = aa * a, bn = bb * b, cn = cc * c;
    //	cout << c << endl;
    //	cout << (a + an) * aa / 2 << endl;
    //	cout << (b + bn) * bb / 2 << endl;
    cout << (1 + n) * n / 2 - (a + an) * aa / 2 - (b + bn) * bb / 2 + (c + cn) * cc / 2;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}