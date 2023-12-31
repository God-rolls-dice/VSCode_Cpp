// #include <bits/stdc++.h>
// using namespace std;
// int M, N, K;
// unordered_map<int, vector<int>> a;
// unordered_map<int, int> p;
// set<int> ans;

// void dfs(int v, int h, map<int, int> &flag)
// {
//     if (h)
//     {
//         for (int i = 0; i < a[v].size(); i++)
//         {
//             if (flag[a[v][i]] < h)
//             {
//                 ans.insert(a[v][i]);
//                 dfs(a[v][i], h - 1, flag);
//                 flag[a[v][i]] = h;
//             }
//         }
//     }

// }

// void solve()
// {
//     cin >> M >> N >> K;
//     int tp1 = 0, tp2 = 0;
//     for (int i = 1; i <= N; i++)
//     {
//         cin >> tp1 >> tp2;
//         a[tp1].emplace_back(tp2);
//         a[tp2].emplace_back(tp1);
//     }
//     map<int, int> flag;
//     for (int i = 1; i <= K; i++)
//     {
//         cin >> tp1 >> tp2;
//         ans.insert(tp1);
//         if(flag[tp1] < 1)
//         {
//             flag[tp1] = 1;
//         }
//         dfs(tp1, tp2, flag);
//     }
//     cout << ans.size() << endl;
//     for (auto i : ans)
//     {
//         cout << i << ' ';
//     }
// }

// signed main()
// {
//     ios :: sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);
//     int t = 1;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);

//     int N, M, K;
//     cin >> N >> M >> K;
//     vector<vector<int>> g(N);
//     for (int i = 0; i < M; i++)
//     {
//         int a, b;
//         cin >> a >> b, --a, --b;
//         g[a].push_back(b), g[b].push_back(a);
//     }
//     vector<int> p(K), h(K);
//     for (int i = 0; i < K; i++)
//         cin >> p[i] >> h[i], p[i]--;

//     vector<int> d(N, -1);
//     priority_queue<pair<int, int>> Q;

//     auto add = [&](int v, int x)
//     {
//         if (d[v] < x)
//             Q.emplace(d[v] = x, v);
//     };
//     for (int i = 0; i < K; i++)
//         add(p[i], h[i]);
//     while (Q.size())
//     {
//         auto [x, v] = Q.top();
//         Q.pop();
//         if (d[v] != x)
//             continue;
//         for (auto &u : g[v])
//             add(u, d[v] - 1);
//     }
//     vector<int> ans;
//     for (int i = 0; i < N; i++)
//         if (d[i] >= 0)
//             ans.push_back(i + 1);

//     cout << ans.size() << "\n";
//     for (int i = 0; i < (int)ans.size(); i++)
//         cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
// }
// //从最长的开始算，截取一段后可能取代更小的长度，不需要每次从最小的位置开始出发

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M, K;
    set<int> ans;
    cin >> N >> M >> K;
    vector<int> edge[N + 5];
    int a, b;
    for (int i = 1; i <= M; i++)
    {
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    int p, h;
    priority_queue<pair<int, int>> que;
    vector<int> v(N + 5, -1);
    for (int i = 1; i <= K; i++)
    {
        cin >> p >> h;
        v[p] = h;
        que.push({h, p});
    }
    auto filt = [&](pair<int, int> a)
    {
        if (v[a.second] < a.first)
        {
            v[a.second] = a.first;
            que.emplace(a);
        }
    };
    while (que.size())
    {
        auto tp = que.top();
        que.pop();
        if (tp.first != v[tp.second])
            continue;
        for (auto j : edge[tp.second])
        {
            filt({tp.first - 1, j});
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (v[i] >= 0)
        {
            ans.insert(i);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
}