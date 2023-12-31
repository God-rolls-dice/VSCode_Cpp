#include <bits/stdc++.h>
using namespace std;
int n, m, T, end_x, end_y;
long long Max = 0;
long long MAX = 0;
void dfs(vector<vector<long long>> &map, int x, int y, long long all)
{
    all += map[x][y];
    if (x < end_x)
    {
        x++;
        dfs(map, x, y, all);
    }
    if (y < end_y)
    {
        y++;
        dfs(map, x, y, all);
    }
    if ((x == end_x) && (y == end_y))
    {
        if (Max < all)
        {
            Max = all;
        }
    }
}
long long dp(vector<vector<long long>> &map, vector<vector<long long>> &done, vector<vector<long long>> &flag, int x, int y)
{
    done[x][y] += map[x][y];
    if (x > 1)
    {
        if (!flag[x - 1][y])
        {
            dp(map, done, flag, x - 1, y);
        }
    }
    if (y > 1)
    {
        if (!flag[x][y - 1])
        {
            dp(map, done, flag, x, y - 1);
        }
    }
}
int main()
{
    cin >> n >> m;
    vector<vector<long long>> map(n + 1, vector<long long>(m + 1, 0)), done(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
    cin >> T;
    long long max_sk = 0, max_ke = 0;
    vector<vector<long long>> s_k(n + 1, vector<long long>(n + 1, 0)), k_e(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= T; i++)
    {
        Max = 0;
        MAX = 0;
        int k;
        cin >> k;
        max_sk = 0, max_ke = 0;
        vector<vector<int>> a(k + 1, vector<int>(2, 0));
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i][0] >> a[i][1];
            end_x = a[i][0];
            end_y = a[i][1];
            if (!s_k[a[i][0]][a[i][1]])
            {
                dfs(map, 1, 1, 0);
                s_k[a[i][0]][a[i][1]] = Max;
                Max = 0;
            }
            if (s_k[a[i][0]][a[i][1]] > max_sk)
            {
                max_sk = s_k[a[i][0]][a[i][1]];
            }
            end_x = n;
            end_y = m;
            if (!k_e[a[i][0]][a[i][1]])
            {
                dfs(map, a[i][0], a[i][1], 0);
                k_e[a[i][0]][a[i][1]] = Max;
                Max = 0;
            }
            if (k_e[a[i][0]][a[i][1]] > max_ke)
            {
                max_ke = k_e[a[i][0]][a[i][1]];
            }
        }
        MAX = max_ke + max_sk;
        dfs(map, 1, 1, 0);
        if (Max > MAX)
        {
            MAX = Max;
        }
        cout << MAX << endl;
    }
}