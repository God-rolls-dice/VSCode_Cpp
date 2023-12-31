#include <bits/stdc++.h>
using namespace std;
int N, M, tp, cnt;
vector<int> q(105, 0);

void dfs(int x)
{
    if (x == N)
    {
        exit(0);
    }
    int n, _;
    cnt++;
    cin >> n;
    vector<int> v(n, 0);
    for (auto &i : v)
    {
        cin >> i;
    }
    for (auto &i : v)
    {
        if (!q[i])
        {
            cout << i << endl;
            q[i]++;
            dfs(i);
            cout << x << endl;
            cin >> _;
            for (auto k : v)
            {
                cin >> _;
            }
        }
    }

}

void solve()
{
    cin >> N >> M;
    q[1]++;
    dfs(1);
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}

