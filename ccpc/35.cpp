#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (int i = (a); i >= (b); --i)

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    int map[N + 5][M + 5][M + 5][5];
    FOR(i, 1, N)
    {
        FOR(j, 1, M)
        {
            map[i][j][j][1] = 0;
            map[i][j][j][2] = 0;
            map[i][j][j][3] = 0;
            char temp;
            int flag;
            cin >> temp;
            if (temp == 'C')
                flag = 1;
            else if (temp == 'M')
                flag = 2;
            else
                flag = 3;
            map[i][j][j][flag]++;
            FOR(k, 1, j - 1)
            {
                map[i][k][j][1] = map[i][k][j - 1][1] + map[i][j][j][1];
                map[i][k][j][2] = map[i][k][j - 1][2] + map[i][j][j][2];
                map[i][k][j][3] = map[i][k][j - 1][3] + map[i][j][j][3];
            }
        }
    }
    FOR(i, 1, K)
    {
        int x_1, x_2, y_1, y_2;
        ll sum_1 = 0, sum_2 = 0, sum_3 = 0;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        FOR(i, x_1, x_2)
        {
            sum_1 += map[i][y_1][y_2][1];
            sum_2 += map[i][y_1][y_2][2];
            sum_3 += map[i][y_1][y_2][3];
        }
        cout << sum_1 << ' ' << sum_2 << ' ' << sum_3 << endl;
    }
    return 0;
}
