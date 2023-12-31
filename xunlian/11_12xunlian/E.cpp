#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 5005;
typedef long long ll;
ll mod = 998244353, f[N][M], ans, sum[M];
int n, m, s;
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++)
        f[1][i] = 1, sum[i] = i;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!s)     //s == 0,表示第一个数前缀和不为0
            {
                f[i][j] = (f[i][j] + sum[m]) % mod;
                continue;
            }
            if (j - s >= 1)     //
                f[i][j] = (f[i][j] + sum[j - s]) % mod;
            if (j + s <= m)     // 
                f[i][j] = (f[i][j] + sum[m] - sum[j + s - 1] + mod) % mod;
        }
        for (int j = 1; j <= m; j++)
            sum[j] = (sum[j - 1] + f[i][j]) % mod;
    }
    for (int i = 1; i <= m; i++)
        ans = (ans + f[n][i]) % mod;
    printf("%lld", ans);
    return 0;
}