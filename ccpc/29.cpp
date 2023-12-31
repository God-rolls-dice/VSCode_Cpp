




// 参数:x字符串长度为m y字符串长度为n
void LCSLength(char x[], char y[], int m，int n)
{
    /* 计算最长公共子序列的长度 */
    int L[m][n], i，j;
    for (i = 0; i <= m; i++)
        L[i][0] = 0;
    for (i = 0; i <= n; i++)
        L[0][i] = 0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i] == y[j])
                L[i][j] = L[i - 1][j - 1] + 1;
            else if (L[i - 1][j] >= L[i][j - 1])
                L[i][j] = L[i - 1][j];
            else
                L[i][j] = L[i][j - 1];
        }
    }
    return L[m][n];
}