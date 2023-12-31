// #include <iostream>
// #include <vector>
// #include <array>
// #include <cstring>
// using namespace std;

// const int Maxn = 110;

// int N, V, v, w, fa, ans;
// vector<array<int, 3>> son[Maxn];
// vector<

// void dp(int p, int f[])
// {
//     int tp_f[Maxn];
//     for (const auto &nx : son[p])
//     {
//         memcpy(tp_f, f, Maxn * sizeof(int));
//         for (int i = V; i >= nx[0]; i--)
//         {
//             tp_f[i] = max(tp_f[i], tp_f[i - nx[0]] + nx[1]);
//         }
//         ans = max(ans, tp_f[V]);
//         if (son[nx[2]].size())
//             dp(nx[2], tp_f);
//     }
// }

// void solve()
// {
//     cin >> N >> V;
//     int f[Maxn] = {0};
//     for (int i = 1; i <= N; i++)
//     {
//         cin >> v >> w >> fa;
//         if (fa == -1)
//         {
//             son[0].push_back({v, w, i});
//         }
//         else
//         {
//             son[fa].push_back({v, w, i});
//         }
//     }
//     dp(0, f);
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);
//     int t = 1;
//     while (t--)
//     {
//         solve();
//     }
//     cout << ans;
// }

#include <iostream>
#include <cstring>

using namespace std;

const int N = 6;

int n, m, root;
int h[N], e[N], ne[N], idx;
int v[N], w[N];
int f[N][N];

void add(int a, int b)  //a表示父节点编号，b代表子节点编号
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;   //e代表编号为0的边终点点编号，idx的边的下一条边的编号，h表示连接的父节点的一个边
}
void dfs(int u)
{
    // 先枚举所有状态体积小于等于j-v[u]的所有子节点们能够获得的最大价值
    for (int i = h[u]; ~i; i = ne[i])   //u代表边的编号，ne代表下一条边的编号
    {
        int son = e[i];
        dfs(son);                           // 从下往上算，先计算子节点的状态
        for (int j = m - v[u]; j >= 0; --j) // 枚举所有要被更新的状态
        {
            for (int k = 0; k <= j; ++k) // 枚举该子节点在体积j下能使用的所有可能体积数
            {
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
            }
        }
    }
    // 最后选上第u件物品
    for (int j = m; j >= v[u]; --j)
        f[u][j] = f[u][j - v[u]] + w[u];
    for (int j = 0; j < v[u]; ++j)
        f[u][j] = 0; // 清空没选上u的所有状态
}
int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int p;
        cin >> v[i] >> w[i] >> p;
        if (p == -1)
            root = i;
        else
            add(p, i);
    }
    dfs(root);
    cout << f[root][m] << endl;
    return 0;
}