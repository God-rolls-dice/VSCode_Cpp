#include <bits/stdc++.h>
using namespace std;
map<int, int> Map;
#define N 100000 + 5;

void solve()
{
    int n;
    cin >> n;
    int a[n + 5] = {0};
    int sum_a[n + 5] = {0};
    cin >> a[1];
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
        if (i % 2 == 1)
        {
            sum_a[i] = a[i] - a[i - 1] + sum_a[i - 1];
        }
        else
        {
            sum_a[i] = sum_a[i - 1];
        }
    }
    int tt;
    cin >> tt;
    int l, r, l_n, r_n;
    for (int i = 1; i <= tt; i++)
    {
        cin >> l >> r;
        l_n = lower_bound(a + 1, a + n + 1, l) - a;
        r_n = lower_bound(a + 1, a + n + 1, r) - a;
        int ans = sum_a[r_n] - sum_a[l_n];
        if (l_n & 1)
        {
            ans += a[l_n] - l;
        }
        if (r_n & 1)
        {
            ans -= a[r_n] - r;
        }
        cout << ans << endl;
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