// #include <iostream>
// #include <vector>
// using namespace std;

// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     int pos = n, flag = true;
//     k = min(n, k);
//     for (int i = 1; i <= k; i++)
//     {
//         if (a[pos] <= n)
//         {
//             pos = (pos - a[pos] + n) % n;
//             if (pos == 0)
//             {
//                 pos = n;
//             }
//         }
//         else
//         {
//             flag = false;
//             break;
//         }
//     }
//     cout << (flag ? "Yes\n" : "No\n");
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int t = 1;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
// }
#include <iostream>
#include <unordered_set>
using namespace std;

int n, k;
int b[200010];
bool vis[200010];

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
    }

    unordered_set<int> s;
    int cur = n;
    bool ok = true;
    for (int i = 1; i <= k; i++)
    {
        if (b[cur] <= n)
        {
            if (vis[cur])
            {
                break;
            }
            else
            {
                vis[cur] = true;
            }
            cur = ((cur - b[cur]) % n + n) % n;
            if (cur == 0)
            {
                cur = n;
            }
        }
        else
        {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes\n" : "No\n");
}

int main()
{
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}
//标准答案