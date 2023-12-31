#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n, tp1, tp2, ans;
vector<pair<int, int>> vec;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tp1 >> tp2;
        tp2 = tp1 + tp2;
        vec.push_back({tp1, tp2});
    }
    sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b){ return a.first < b.first; });
    multiset<int> res;
    int flag = 0, tp = 0;
    while(res.size() != 0 || flag < n)
    {
        if (res.size() == 0)
        {
            tp = vec[flag].first;
        }
        while (vec[flag].first == tp)
        {
            res.insert(vec[flag].second);
            flag++;
        }
        while (res.size() && *res.begin() < tp)
        {
            res.erase(res.begin());
        }
        if (res.size() && *res.begin() >= tp)
        {
            ans++;
            res.erase(res.begin());
        }
        tp++;
    }
    cout << ans;
}