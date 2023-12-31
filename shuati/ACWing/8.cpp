#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, V, M, v, m, w;

int main()
{
    cin >> N >> V >> M;
    int f[V + 1][M + 1] = {0};
    for (int i = 0; i <= N; i++)
    {
        cin >> v >> m >> w;
        for (int j = V; j >= v; j--)
        {
            for (int k = M; k >= m; k--)
            {
                f[j][k] = max(f[j][k], f[j - v][k - m] + w);
            }
        }
    }
    cout << f[V][M];
}