#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e3 + 10;
int row, col, ans;
char c[Maxn][Maxn], fg[Maxn][Maxn];
void dp(int x, int y)
{
    if (c[x + 1][y - 1] == '#' && fg[x + 1][y - 1] == 0)
    {
        fg[x + 1][y - 1]++;
        dp(x + 1, y - 1);
    }
    if (c[x + 1][y] == '#' && fg[x + 1][y] == 0)
    {
        fg[x + 1][y]++;
        dp(x + 1, y);
    }
    if (c[x + 1][y + 1] == '#' && fg[x + 1][y + 1] == 0)
    {
        fg[x + 1][y + 1]++;
        dp(x + 1, y + 1);
    }
    if (c[x][y + 1] == '#' && fg[x][y + 1] == 0)
    {
        fg[x][y + 1]++;
        dp(x, y + 1);
    }
    if (c[x][y - 1] == '#' && fg[x][y - 1] == 0)
    {
        fg[x][y - 1]++;
        dp(x, y - 1);
    }
    if (c[x - 1][y - 1] == '#' && fg[x - 1][y - 1] == 0)
    {
        fg[x - 1][y - 1]++;
        dp(x - 1, y - 1);
    }
    if (c[x - 1][y] == '#' && fg[x - 1][y] == 0)
    {
        fg[x - 1][y]++;
        dp(x - 1, y);
    }
    if (c[x - 1][y + 1] == '#' && fg[x - 1][y + 1] == 0)
    {
        fg[x - 1][y + 1]++;
        dp(x - 1, y + 1);
    }
}
int main()
{
    cin >> row >> col;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (c[i][j] == '#')
            {
                if (fg[i][j] == 0)
                {
                    ans++;
                }
                dp(i, j);
            }
        }
    }
    cout << ans;
}
