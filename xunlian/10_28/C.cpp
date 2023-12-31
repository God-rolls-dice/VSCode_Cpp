#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, MAX = 1e9;
int n, m, tp, Max; // 树状数组
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        cin >> tp;
        a.push_back(tp);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n && a[i] + m - 1 <= a.back(); i++)
    {
        if (Max < upper_bound(a.begin(), a.end(), a[i] + m - 1) - (a.begin() + i))
        {
            Max = upper_bound(a.begin(), a.end(), a[i] + m - 1) - (a.begin() + i);
        }
    }
    cout << Max;
}