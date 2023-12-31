#include <iostream>
#include <vector>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m, ans;

long dfs(long long x, vextor<vextor<long long>> &num)
{
    if (num[x][0] != 0)
    {
        ans = (ans + num[x][0]) % mod;
        return num[x][0];
    }
    else
    {
        num[x][0] = num[x][0] + x;
        ans = (ans + x)%mod;
        for (long long i = 2; i <= n; i++)
        {
            if (x < i)
            {
                break;
            }
            else
            {
                if (x % i == 0)
                {
                    if(num[x][i])
                    num[x][i] = num[x][i] + dfs(x - x / i, num);
                    num[x][i] = num[x][i] % mod;
                }
            }
        }
        return num[x];
    }
}

int main()
{
    ans = 0;
    cin >> n >> m;
    vector<vector<long long>> num(m, vector<long long>(n));
    dfs(m, num);
    cout << ans << endl;
    return 0;
}
