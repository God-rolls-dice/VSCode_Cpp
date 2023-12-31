
``` C++

//二位地图的深度优先遍历

const int N = ;     //范围
Map[N][N]   //记录地图
cnt[N][N]   //记录步数
dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};     //前进的方向

void bfs(int sx, int sy)
{
    memset(cnt, 0x3f, sizeof(cnt));     //步数变为最大值
    cnt[sx][sy] = 0;
    queue<array<int, 2>> q;
    q.push({sx, sy});
    while (q.size())
    {
        auto[hx, hy] = q.front();
        q.pop();
        rep(i, 0, 3)
        {
            int nx = dir[i][0] + hx, ny = dir[i][1] + hy;
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m)
            {
                if (Map[nx][ny] != -1 && ckmin(cnt[nx][ny], cnt[hx][hy] + 1))   //满足地图条件并且选中最短的道路
                {
                    q.push({nx, ny});   //因为队列是先进先出所以第一轮完了才会到第二轮所以满足BFS的要求
                }
            }
        }
    }
}
