#include <iostream>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (auto i = (a); i >= (b); --i)
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, min = 1005, max = -1, temp, sum = 0;
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> temp;
        if (temp >= max)
        {
            max = temp;
        }
        if (temp <= min)
        {
            min = temp;
        }
        sum += temp;
    }
    double left = (sum - max) / (n - 1.0);
    double right = (sum - min) / (n - 1.0);
    printf("%.6f %.6f", left, right);
    return 0;
}
#include <bits/stdc++.h>

void cout_percision(int n)
{
    std::cout.setf(std::ios::fixed);
    std::cout.precision(n);
}

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());

    int sum = std::accumulate(a.begin(), a.end(), 0);
    double l = 1.0 * (sum - a[n - 1]) / (n - 1);
    double r = 1.0 * (sum - a[0]) / (n - 1);

    std::cout << l << ' ' << r << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // std::cout.precision(6);
    cout_percision(6);

    int tt = 1;
    // std::cin >> tt;

    while (tt--)
    {
        solve();
    }
    return 0;
}
