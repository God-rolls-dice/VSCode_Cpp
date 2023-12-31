#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
const long long MOD = 1e9 + 7;
long long a[2][N + 1] = {0};
int init(int n)
{
    a[0][1] = 1;
    int flag = 0;
    for (int i = 2; i <= n; i++)
    {
        if (flag == 0)
        {
            for (int j = 1; j <= i; j++)
            {
                a[1][j] = (a[0][j] + a[0][j - 1]) % MOD;
            }
            flag = 1;
        }
        else
        {
            for (int j = 1; j <= i; j++)
            {
                a[0][j] = (a[1][j] + a[1][j - 1]) % MOD;
            }
            flag = 0;
        }
    }
    return flag;
}
int main()
{

    long long num = 1;
    int n;
    cin >> n;
    int l = init(n);
    for (int i = 1; i <= n; i++)
    {
        num = (num * a[l][i]) % MOD;
    }
    cout << num;
}