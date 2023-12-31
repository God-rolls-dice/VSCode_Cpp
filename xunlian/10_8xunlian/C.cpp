#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, m, k, cnt = 0;
    cin >> n >> m >> k;
    if (k >= 4)
    {
        cnt = 0;
    }
    else if (k == 3)
    {
        if (m > n)
        {
            cnt = m - n - m / n + 1;
        }
        else
        {
            cnt = 0;
        }
    }
    else if (k == 2)
    {
        if (m >= n)
        {
            cnt = m / n + n - 1;
        }
        else
        {
            cnt = m;
        }
    }
    else if (k == 1)
    {
        cnt = 1;
    }
    cout << cnt << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}