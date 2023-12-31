#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    int score1 = 0, score2 = 0, flag = 0, temp = 0;
    cin >> n >> m;
    int num[n + 1][m + 1];
    string a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        for (int j = 0; j < m; j++)
        {
            num[i][j] = a[j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
            {
                flag = num[i][j];
                temp = 1;
            }
            else
            {
                while (j < m && flag == num[i][j])
                {
                    temp++;
                    j++;
                }
                if (temp >= 5)
                {
                    if (flag == 1)
                    {
                        score1 = score1 + temp - 4;
                    }
                    else if (flag == 2)
                    {
                        score2 = score2 + temp - 4;
                    }
                }
                flag = num[i][j];
                temp = 1;
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                flag = num[i][j];
                temp = 1;
            }
            else
            {
                while (i < n && flag == num[i][j])
                {
                    temp++;
                    i++;
                }
                if (temp >= 5)
                {
                    if (flag == 1)
                    {
                        score1 = score1 + temp - 4;
                    }
                    else if (flag == 2)
                    {
                        score2 = score2 + temp - 4;
                    }
                }
                flag = num[i][j];
                temp = 1;
            }
        }
    }
    // for (int i = 0; i < n - 4; i++)
    // {
    //     for (int j = 0; j < m - 4; j++)
    //     {
    //         if (num[i][j] == 1 && num[i + 1][j + 1] == 2 && num[i + 2][j + 2] == 2 && num[i + 3][j + 3] == 1 && num[i + 4][j + 4] == 1)
    //             score1++;
    //         else if (num[i][j] == 2 && num[i + 1][j + 1] == 2 && num[i + 2][j + 2] == 2 && num[i + 3][j + 3] == 2 && num[i + 4][j + 4] == 2)
    //             score2++;
    //     }
    // }

    // for (int i = 0; i < n - 4; i++)
    // {
    //     for (int j = 4; j < m; j++)
    //     {
    //         if (num[i][j] == 1 && num[i + 1][j - 1] == 1 && num[i + 2][j - 2] == 1 && num[i + 3][j - 3] == 1 && num[i + 4][j - 4] == 1)
    //             score1++;
    //         else if (num[i][j] == 2 && num[i + 1][j - 1] == 2 && num[i + 2][j - 2] == 2 && num[i + 3][j - 3] == 2 && num[i + 4][j - 4] == 2)
    //             score2++;
    //     }
    // }
    cout << score1 << " " << score2;
}