#include <bits/stdc++.h>
using namespace std;
#define int long long
map<char, int> Map;
char a[505][505];
void solve()
{
    int H, W;
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int cnt = 0;
            if (a[i][j] == '.')
            {
                if(a[i - 1][j] == '#')
                {
                    cnt ++;
                }
                if(a[i + 1][j] == '#')
                {
                    cnt++;
                }
                if(a[i][j - 1] == '#')
                {
                    cnt++;
                }
                if(a[i][j + 1] == '#')
                {
                    cnt++;
                }
                if(cnt >= 2)
                {
                    cout << i << ' ' << j;
                    return;
                }

            }
        }
    }
}

signed main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}