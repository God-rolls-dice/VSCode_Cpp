#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3010;
int grid[Maxn][Maxn] = {0};
long long ans, H, W, N, l, r;

void solve()
{
    cin >> H >> W >> N;
    ans = H * W - N;
    for (int i = 1; i <= N; i ++)
    {
        cin >> l >> r;
        grid[l][r] = 1;
    }
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            grid[i][j] = grid[i][j] + grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            l = 1; 
            int h = H - i, w = W - j;
            r = min(h, w);
            if (r > 0)
            {
                int mid = (l + r + 1) / 2;
                if (grid[i + 1][j + 1] - (grid[i - 1][j + 1] + grid[i + 1][j - 1] - grid[i - 1][j - 1]) == 0)
                {
                    while (l < r)
                    {
                        if (grid[i + mid][j + mid] - (grid[i - 1][j + mid] + grid[i + mid][j - 1] - grid[i - 1][j - 1]) == 0)
                        {
                            l = mid;
                        }
                        else
                        {
                            r = mid - 1;
                        }
                        mid = (l + r + 1) / 2;
                    } 
                    ans = ans + l;
                }
            }
        }
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t --)
    {
        solve();
    }

}