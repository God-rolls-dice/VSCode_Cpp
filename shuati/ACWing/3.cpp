#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e3 + 10;
int v[Maxn], w[Maxn], N, V;
int main()
{
    cin >> N >> V;
    int f[V + 1];
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = v[i]; j <= V; j++)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[V];
}