#include <bits/stdc++.h>
using namespace std;
int n, m;

int countSquares(vector<vector<char>> &matrix)
{
    int m = matrix.size();                       // 矩阵行数
    int n = matrix[0].size();                    // 矩阵列数
    vector<vector<char>> dp(m, vector<char>(n)); // 定义状态矩阵
    int count = 0;                               // 记录全部由1构成的正方形的数量

    // 初始化状态矩阵的第一行和第一列
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = matrix[i][0];
    }
    for (int j = 1; j < n; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    // 计算状态矩阵的其余部分
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                if (dp[i][j] > 1)
                {
                    count++;
                }
            }
        }
    }

    return count;
}
int main()
{

    char temp = 0;
    cin >> n >> m;
    int all = n * m;
    if (m > n)
    {
        swap(m, n);
    }
    vector<vector<char>> a(n), b(m, vector<char>(n, 0)), c(m, vector<char>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            a[i].push_back(temp);
        }
    }

    for (int i = 0; i < n; i++) // 字串的宽度
    {
        for (int j = 0; j < m; j++)
        {
            b[j][n - 1 - i] = a[i][j];
        }
    }
    for (int k = 0; k <= n - m; k++)
    {
        for (int i = k; i < k + m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == b[i - k][n - m - k + j])
                {
                    c[i - k][j] = 1;
                }
            }
        }
        all += countSquares(c);
    }
    cout << all;
}