#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (auto i = (a); i >= (b); --i)
const int N = 1010;
int m, n, num[N][N], flag;
char temp;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            cin >> temp;
            num[i][j] = temp - '0';
        }
    }
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            if (!num[i][j])
            {
                if ((num[i + 1][j] + num[i - 1][j] + num[i][j + 1] + num[i][j - 1] >= 3) && ((num[i + 1][j] != 2) && num[i - 1][j] != 2) && (num[i][j + 1] != 2) && (num[i][j - 1] != 2))
                    flag++;
            }
        }
    }
    if (flag)
    {
        cout << "YES" << endl
             << flag;
    }
    else
    {
        cout << "NOP";
    }
    return 0;
}