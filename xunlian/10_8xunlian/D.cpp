#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
#define N 100000 + 10
int a[N + 5];
int Pow[N + 5];
map<int, int> Map;

void solve()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

    }
    for (int j = 1; j <= n; j++)
    {
        int Max = 0;
        for (int k = 1; k * j <= n; k++)
        {
            Max = max(Max, a[k * j]);
        }
        Map[Max]++;
    }
    for (auto i = --Map.end(); i != Map.begin(); i--)
    {
        ans = (ans + ((Pow[i -> second] - 1) * Pow[n - i -> second]) % MOD * i -> first % MOD) % MOD;
        n -= i -> second;
    }
    auto i = Map.begin();
    ans = (ans + ((Pow[i->second] - 1) * Pow[n - i->second]) % MOD * i->first % MOD) % MOD;
    cout << ans;
}

signed main()
{
    int t = 1;
    Pow[0] = 1;
    for (int i = 1; i < N + 5; i++)
    {
        Pow[i] = (Pow[i - 1] * 2) % MOD;
    }
    while (t--)
    {
        solve();
    }
    return 0;
}