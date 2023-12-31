#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
     int n, m, x, begin_x, begin_y, end_x, end_y;
     cin >> n >> m >> x;
     cin >> begin_x >> begin_y >> end_x >> end_y;
     vector<vector<int>> map(n + 2, vector<int>(m + 2, -1));
     for (int i = 1; i <= n; i++)
     {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
     }
    deque<pair<int, int>> tovisit;
    vector<vector<int>> sorce(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> visited(n + 2, vector<int>(m + 2, 0));
    int num = 0;
    bool flag = false;
    tovisit.push_back({begin_x,begin_y});
    visited[begin_x][begin_y]++;
    while (!tovisit.empty())
    {
        for (int i = 1; i <= n + 1; i++)
        {
            fill(visited[i].begin(), visited[i].end(), 0ll);
            visited[begin_x][begin_y]++;
        }
        num++;
        deque<pair<int, int>> tp(tovisit.begin(), tovisit.end());
        tovisit.clear();
        while (!tp.empty())
        {
            auto [x, y] = tp.front();
            tp.pop_front();
            if (map[x + 1][y] != -1)
            {
                if (sorce[x][y] + map[x + 1][y] > x && (x + 1 == end_x && y == end_y))
                {
                    flag = true;
                }
                if (visited[x + 1][y] == 0)
                {
                    visited[x + 1][y] ++;
                    sorce[x + 1][y] = sorce[x][y] + map[x + 1][y];
                    tovisit.push_back({x + 1, y});
                }
                else if (sorce[x + 1][y] < sorce[x][y] + map[x + 1][y])
                {
                    sorce[x + 1][y] = sorce[x][y] + map[x + 1][y];
                }
            }
            if (map[x - 1][y] != -1)
            {
                if (sorce[x][y] + map[x - 1][y] > x && (x - 1 == end_x &&y == end_y))
                {
                    flag = true;
                }
                if (visited[x - 1][y] == 0)
                {
                    visited[x - 1][y]++;
                    sorce[x - 1][y] = sorce[x][y] + map[x - 1][y];
                    tovisit.push_back({ x - 1, y });
                }
                else if (sorce[x - 1][y] < sorce[x][y] + map[x - 1][y])
                {
                    sorce[x - 1][y] = sorce[x][y] + map[x - 1][y];
                }
            }
            if (map[x][y + 1] != -1)
            {
                if (sorce[x][y] + map[x][y + 1] > x && (x == end_x && y + 1 == end_y))
                {
                    flag = true;
                }
                if (visited[x][y + 1] == 0)
                {
                    visited[x][y + 1]++;
                    sorce[x][y + 1] = sorce[x][y] + map[x][y + 1];
                    tovisit.push_back({x, y + 1});
                }
                else if (sorce[x][y + 1] < sorce[x][y] + map[x][y + 1])
                {
                    sorce[x][y + 1] = sorce[x][y] + map[x][y + 1];
                }
            }
            if (map[x][y - 1] != -1)
            {
                if (sorce[x][y] + map[x][y - 1] > x && (x == end_x && y - 1 == end_y))
                {
                    flag = true;
                }
                if (visited[x][y - 1] == 0)
                {
                    visited[x][y - 1]++;
                    sorce[x][y - 1] = sorce[x][y] + map[x][y - 1];
                    tovisit.push_back({x, y - 1 });
                }
                else if (sorce[x][y - 1] < sorce[x][y] + map[x][y - 1])
                {
                    sorce[x][y - 1] = sorce[x][y] + map[x][y - 1];
                }
            }
        }
        if (flag)
        {
            break;
        }
        
    }
    if (flag)
    {
        cout << num;
    }
}