#include <bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn = 1e2 + 10;
int v[Maxn], w[Maxn], s[Maxn], N, V;
signed main()
{
    cin >> N >> V;
    int f[V + 1], cnt[V + 1];
    memset(f, 0, sizeof(f));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i] >> w[i] >> s[i];
    }
    for (int i = 1; i <= N; i++)
    {
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1; j <= s[i]; j++)
        {
            for (int k = V; k >= v[i]; k--)
            {
                f[k] = max(f[k], f[k - v[i]] + w[i]);
            }
        }
    }
    cout << f[V];
}