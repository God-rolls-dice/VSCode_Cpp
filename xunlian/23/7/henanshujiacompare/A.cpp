#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (auto i = (a); i >= (b); --i)
const ll N = 1e12 + 10;
__int128 n, i, k, mod = 1000000007, flag, sum, num[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> k;
    for (ll n = 1; n <= k; n++)
    {
        flag = 0;
        for (ll j = 1; j <= n; j++)
        {
            if (gcd(j, i) == 1)
            {
                flag++;
                flag = flag % mod;
            }
        }
        if (n > 1)
        {
            if (n % 2 == 0)
            {
                sum += ((((1 + n) * (n / 2) / N) % mod) * flag) % mod;
            }
            else
            {
                sum = ((((sum + (1 + n) * (n / 2) + n / 2 + 1)) / n) % mod * flag) % mod;
            }
        }
        else
        {
            sum += 1;
        }
    }
    cout << sum;
    return 0;
}