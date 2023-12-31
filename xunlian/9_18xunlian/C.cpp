#include <bits/stdc++.h>
using namespace std;
// void solve()
// {
//     string s;
//     cin >> s;
//     int n = s.size() - 1, cnt = 0, sort = 0, unsort = 3e5;
//     for (int i = 0; i <= n; i++)
//     {
//         if (s[i] == '+')
//         {
//             cnt++;
//         }
//         else if (s[i] == '-')
//         {
//             cnt--;
//             if (cnt > 0 && sort > cnt)
//             {
//                 sort = cnt;
//             }
//             if (unsort > cnt)
//             {
//                 unsort = 3e5;
//             }

//         }
//         else if (s[i] == '1')
//         {
//             if (unsort <= cnt)
//             {
//                 cout << "NO" << endl;
//                 return;
//             }
//             sort = max(cnt, sort);
//         }
//         else
//         {
//             if (cnt < 2 || sort >= cnt)
//             {
//                 cout << "NO" << endl;
//                 return;
//             }
//             unsort = min(unsort, cnt);
//         }
//     }
//     cout << "YES" << endl;
// }
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.size() - 1, cnt = 0, sort = 0;
    vector<int> unsort;
    for (int i = 0; i <= n; i++)
    {
        if (s[i] == '+')
        {
            cnt++;
        }
        else if (s[i] == '-')
        {
            if (cnt == sort)
            {
                sort--;
            }
            if (unsort.size() > 0 && cnt == unsort.back())
            {
                unsort.pop_back();
            }
            cnt--;
        }
        else if (s[i] == '1')
        {
            if (cnt >= 2 && unsort.size())
            {
                cout << "NO" << endl;
                return;
            }
            sort = cnt;
            unsort.clear();
        }
        else
        {
            if (cnt < 2 || cnt == sort)
            {
                cout << "NO" << endl;
                return;
            }
            unsort.push_back(cnt);
        }
    }
    cout << "YES" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
int main()
{
    int t;
    cin >> t;
    while (t --)
    {
        solve();
    }
}