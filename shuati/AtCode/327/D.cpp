#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 6;
int n, m, a[MAXN], b[MAXN];
vector<vector<int>> edges;
vector<int> visited, x, parent;
bool valid = true;

int reflect(int a)
{
    if (a == 0)
        return 1;
    else
        return 0;
}

void dfs(int u, int p)
{
    visited[u] = 1;
    x[u] = reflect(x[p]);
    for (const auto &v : edges[u])
    {
        if (v != p && valid)
        {
            if (visited[v] == 0)
            {
                dfs(v, u);
            }
            if (visited[v] == 1)
            {
                if (x[v] == x[u])
                {
                    valid = false;
                }
            }
        }
    }
    return;
}

int main(void)
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    x.resize(n + 6, -1);
    edges.resize(n + 6);
    visited.resize(n + 6, 0);
    for (int i = 1; i <= m; ++i)
    {
        if (a[i] == b[i])
        {
            cout << "No\n";
            return 0;
        }
        edges[a[i]].emplace_back(b[i]);
        edges[b[i]].emplace_back(a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == 0)
        {
            x[i] = 1;
            dfs(i, i);
        }
        if (!valid)
        {
            break;
        }
    }
    if (valid)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}