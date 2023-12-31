#include <iostream>
#include <algorithm>
using namespace std;
int a[3][3], b[3];
pair<int, int> p[9];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
            p[i * 3 + j] = {i, j};
        }
    }
    double ans = 0;
    do
    {
        bool flag = 1;
        for (int i = 0; i < 3; i++)
        {
            int num = 0;
            for (int j = 0; j < 9; j++)
            {
                if (p[j].first == i)
                {
                    b[num++] = a[i][p[j].second];
                }
            }
            if (b[0] == b[1])
            {
                flag = 0;
                break;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            int num = 0;
            for (int j = 0; j < 9; j++)
            {
                if (p[j].second == i)
                {
                    b[num++] = a[p[j].first][i];
                }
            }
            if (b[0] == b[1])
            {
                flag = 0;
                break;
            }
        }
        int num = 0;
        for (int j = 0; j < 9; j++)
        {
            if (p[j].first == p[j].second)
            {
                b[num++] = a[p[j].first][p[j].second];
            }
        }
        if (b[0] == b[1])
        {
            flag = 0;
        }
        num = 0;
        for (int j = 0; j < 9; j++)
        {
            if (p[j].first == 2 - p[j].second)
            {
                b[num++] = a[p[j].first][p[j].second];
            }
        }
        if (b[0] == b[1])
        {
            flag = 0;
        }
        if (flag)
        {
            ans += 1.0 / 362880;
        }
    } while (next_permutation(p, p + 9));
    printf("%.15lf\n", ans);
    return 0;
}