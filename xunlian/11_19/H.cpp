#include <bits/stdc++.h>
using namespace std;
#define int long long
int H, W, tp, ans;
char S[25][25];
int fg[25][25];
void solve()
{ 
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> S[i][j];
        }
    }
    queue<pair<int, int>> q;
    for (int i = 1; i <= H ; i++)
    {
        for (int j = 1; j <= W ; j++)
        {
            if (S[i][j] == '.')
            {
                q.push({i, j});
                while(q.size())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    if (x + 1 <= H && S[x + 1][y] == '.' && (fg[x][y] + 1 < fg[x + 1][y] || fg[x + 1][y] == 0) && (x + 1 != i || y != j))
                    {
                        q.push({x + 1, y});
                        fg[x + 1][y] += fg[x][y] + 1;
                    }
                    if (y + 1 <= W && S[x][y + 1] == '.' && (fg[x][y] + 1 < fg[x][y + 1] || fg[x][y + 1] == 0) && (x != i || y + 1 != j))
                    {
                        q.push({x, y + 1});
                        fg[x][y + 1] += fg[x][y] + 1;
                    }
                    if (x - 1 >= 1 && S[x - 1][y] == '.' && (fg[x][y] + 1 < fg[x - 1][y] || fg[x - 1][y] == 0) && (x - 1 != i || y != j))
                    {
                        q.push({x - 1, y});
                        fg[x - 1][y] += fg[x][y] + 1;
                    }
                    if (y - 1 >= 1 && S[x][y - 1] == '.' && (fg[x][y] + 1 < fg[x][y - 1] || fg[x][y - 1] == 0) && (x != i || y - 1 != j))
                    {
                        q.push({x, y - 1});
                        fg[x][y - 1] += fg[x][y] + 1;
                    }

                }
                for (int m = 1; m <= H; m++)
                {
                    for (int n = 1; n <= W; n++)
                    {
                        if (fg[m][n] > ans)
                        {
                            ans = fg[m][n];
                        }
                    }
                }
                memset(fg, 0, sizeof(fg));
            }
        }
    }
    cout << ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
}