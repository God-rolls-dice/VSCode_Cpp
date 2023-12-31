#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200000 + 5
int a[N]; 
unordered_map<int, int> Map;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != i)
        {
            Map[a[i]]++;
        }
    }
    vector<pair<int, int>> vec(Map.begin(), Map.end());
    sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b){a.second > b.second;});
    for (int i)
}


signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
}

