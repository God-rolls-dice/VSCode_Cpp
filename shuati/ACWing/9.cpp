#include <bits/stdc++.h>
using namespace std;
int N, V, n, v, w;
int main()
{
    cin >> N >> V;
    int f[V + 1] = {0}, tp1[V + 1] = {0}, tp2[V + 1] = {0};
    for (int i = 1; i <= N; i++)
    {
        cin >> n;
        memcpy(tp2, f, sizeof(f));
        for (int j = 1; j <= n; j++)
        {
            cin >> v >> w;
            memcpy(tp1, tp2, sizeof(tp2));
            for (int l = V; l >= v; l--)
            {
                tp1[l] = max(tp1[v], tp1[l - v] + w);
                if (f[l] < tp1[l])
                {
                    f[l] = tp1[l];
                }
            }
        }
    }
    cout << f[V];
}