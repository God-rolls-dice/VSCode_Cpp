#include <bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn = 55;
int a[Maxn][Maxn];
int n, k, ans, tp;;
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> tp;
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + tp;
        }
    }
    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= n; j++)
        {
            tp = a[i][j] - (a[i][j - k] + a[i - k][j] - a[i - k][j - k]);
            if (ans < tp)
            {
                ans = tp;
            }
        }
    }
    cout << ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
}