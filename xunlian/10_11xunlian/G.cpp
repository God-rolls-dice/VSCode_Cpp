#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long N;
    int M, n;
    cin >> N >> M;
    vector<vector<int>> vec(7);
    set<string> t;
    set<string> f;
    for (int i = 1; i <= M; i++)
    {
        cin >> s;
        vec[s.size()].emplace_back(s);
        f.insert(s);
    }
    for (int i = 3; i <= 6; i++)
    {
        for (auto x : vec[i])
        {
            if (f.find(x.str(0, x.size() - 1) != f.end()))
            {
                t.earse()
            }
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
}