#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, first;
long long max_map = LLONG_MAX;
bool found(vector<vector<int>> &count, vector<vector<ll>> &map, vector<vector<ll>> &map_b, vector<vector<ll>> &Max_n, vector<vector<ll>> &Max_w, int start, int end)
{
    if (map[start][end] != LLONG_MAX)
    {
        ll temp = (max(Max_w[first][start], Max_w[start][end])) * (max(Max_n[first][start], Max_n[start][end]));
        if (temp < max_map)
        {
            max_map = temp;
            map_b[first][end] = temp;
            Max_w[first][end] = max(Max_w[first][start], Max_w[start][end]);
            Max_w[end][first] = Max_w[first][end];
            Max_n[first][end] = max(Max_n[first][start], Max_n[start][end]);
            Max_n[end][first] = Max_n[first][end];
        }
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (count[i])
            {
                continue;
            }
            else if (map[start][i] != LLONG_MAX)
            {
                count_2[i]++;
                ll temp = max(Max_n[first][i], Max_n[i][end]) * max(Max_w[first][i], Max_w[i][end]);
                if (temp < map_b[first][end])
                {
                    max_map = temp;
                    map_b[first][end] = max_map;
                    Max_n[first][end] = max(Max_n[first][i], Max_n[i][end]);
                    Max_n[end][first] = Max_n[first][end];
                    Max_w[first][end] = max(Max_w[first][i], Max_w[i][end]);
                    Max_w[end][first] = Max_w[first][end];
                }
            }
        }
        return 0;
    }
}

void dfs(vector<int> &count, vector<vector<ll>> &map, vector<vector<ll>> &map_b, vector<vector<ll>> &Max_n, vector<vector<ll>> &Max_w, int start, int end)
{
    vector<int> count_2(n + 1, 0);
    if (map[start][end] != LLONG_MAX)
    {
        ll temp = (max(Max_w[first][start], Max_w[start][end])) * (max(Max_n[first][start], Max_n[start][end]));
        if (temp < max_map)
        {
            max_map = temp;
            map_b[first][end] = temp;
            Max_w[first][end] = max(Max_w[first][start], Max_w[start][end]);
            Max_w[end][first] = Max_w[first][end];
            Max_n[first][end] = max(Max_n[first][start], Max_n[start][end]);
            Max_n[end][first] = Max_n[first][end];
        }
    }
    else
    {
        int flag_1 = 0, flag_2 = 0, all = 0;

        while (!flag_1)
        {
            if (flag_2 == 0)
            {
                for (int i = 1; i <= n; i++)
                {
                    if (i != first)

                    {
                        if (map[start][i] != LLONG_MAX)
                        {
                            count[i]++;
                        }
                    }
                }
                for (int i = 1; i <= n; i++)
                {
                    if (count[i] == 1)
                    {
                        flag_1 = +found(count, count_2, map, map_b, Max_n, Max_w, i, end);
                    }
                }
                flag_2++;
            }
            else
            {
                for (int i = 1; i <= n; i++)
                {
                    count[i] = 0;
                    count[i] = count_2[i];
                    count_2[i] = 0;
                }
                for (int i = 1; i <= n; i++)
                {
                    if (count[i] == 1)
                    {
                        flag_1 = +found(count, map, map_b, Max_n, Max_w, i, end);
                    }
                    all++;
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    vector<vector<ll>> map(n + 1, vector<ll>(n + 1, LLONG_MAX)), Max_n(n + 1, vector<ll>(n + 1, 0)), Max_w(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> map[i][i];
    }
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        map[a][b] = c;
        map[b][a] = c;
        Max_w[a][b] = c;
        Max_w[b][a] = c;
    }
    for (int i = 1; i <= n; i++)
    {
        map[i][i] = 0;
        for (int j = i; j <= n; j++)
        {
            Max_n[i][j] = max(i, j);
            Max_n[j][i] = Max_n[i][j];
        }
    }
    vector<vector<ll>> map_b(map);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (map[i][j] == LLONG_MAX)
            {
                vector<int> count(n + 1, 0);
                first = i;
                dfs(count, map, map_b, Max_n, Max_w, i, j);
            }
            cout << map_b[i][j] << ' ';
        }
        cout << endl;
    }
}
