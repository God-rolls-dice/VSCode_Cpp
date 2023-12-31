#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
const long long MOD = 1e9 + 7;

long long init(long long a, long long b)
{
    long long c = a;
    for (long long i = a + 1; i <= b; i++)
    {
        c = c * i;
    }
    return c;
}
int main()
{
    long long n;
    long long num = 1;
    cin >> n;
    long long *a = new long long[n + 1];
    a[0] = 1;
    for (long long i = 2; i < n; i++)
    {
        num = (num * (init(i, n - 1) / init(1, i - 1)) % MOD) % MOD;
    }
    cout << num;
}
