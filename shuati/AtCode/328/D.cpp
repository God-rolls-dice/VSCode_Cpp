#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M, K, fa[56];
long long sum, Min = LLONG_MAX;
int get(int x) 
{
    if (x == fa[x]) 
        return x;
    return fa[x] = get(fa[x]);
}
void solve()
{
    int u, v, w;
    cin >> N >> M >> K;
    vector<array<int, 3>> weight;
    for (int i = 1; i <= M; i++)
    {
        cin >> u >> v >> w;
        w = w % K;
        weight.push_back({u, v , w});
    }
    sort(weight.begin(), weight.end(), [](array<int, 3> a, array<int, 3> b){return a[2] < b[2];});
    for (int i = 0; i < N; i++)
    {
        fa[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int x = get(weight[i][0]);
        int y = get(weight[i][1]);
        if (x == y) continue;
        fa[x] = y;
        sum = (sum + weight[i][2]) % K;
    }
    cout << sum;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
}