#include <bits/stdc++.h>
using namespace std;
struct Resident
{
    long long cost;
    long long n;
} a[100000 + 5];
void solve()
{
    memset(a, 0, sizeof(a));
    long long n, cost;
    cin >> n >> cost;
    long long ans = cost;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].n;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].cost;
    }
    sort(a + 1, a + n + 1, [](Resident a, Resident b)
         { return a.cost < b.cost; });
    n --;
    for (int i = 1; a[i].cost <= cost && n > 0; i++)
    {
        if (a[i].n <= n)
        {
            ans += a[i].cost * a[i].n;
            n -= a[i].n;
        }
        else
        {
            ans += a[i].cost * n;
            n = 0;
        }
    }
    ans += cost * n;
    cout << ans << endl;
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