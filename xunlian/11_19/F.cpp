#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, c, flag = 0, num;

void solve()
{
    num = 0, flag = 0;
    cin >> a >> b >> c;
    int Min = min(a, b);
    Min = min(Min, c);
    a -= Min;
    b -= Min;
    flag 
    cout << num << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}