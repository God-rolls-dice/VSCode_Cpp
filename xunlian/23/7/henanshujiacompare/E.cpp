// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
// #define DEC(i, a, b) for (auto i = (a); i >= (b); --i)
// const int N = 1e6 + 10;
// int num[N];
// vector<int> am;
// int n, m, temp, nu;
// void pick(int st, int flag)
// {
//     if (st > n - 1)
//     {
//         return;
//     }
//     if (flag > m)
//     {
//         return;
//     }
//     else if (flag == m)
//     {
//         nu++;
//     }
//     pick(++st, flag);
//     flag += am[st - 1];
//     pick(st, flag);
// }
// int main()
// {
//     ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

//     cin >> n >> m;
//     FOR(i, 1, n)
//     {
//         cin >> temp;
//         am.push_back(temp);
//     }
//     sort(am.begin(), am.end());
//     auto ed = upper_bound(am.begin(), am.end(), m);
//     if (ed != am.begin())
//     {
//         n = (int)(ed - am.begin());
//         pick(0, 0);
//     }
//     cout << nu;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (auto i = (a); i >= (b); --i)
const int N = 1e6 + 10;
int n, m, num[N], temp, flag, all;
void solve()
{
    int l = 1, r = 0;
    while (r <= n)
    {
        all += num[r++];
        if (all == m)
        {
            flag++;
        }
        while ((all > m) && (l < r))
        {
            all -= num[l++];
            if (all == m)
            {
                flag++;
            }
        }
        }
    cout << flag;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    FOR(i, 1, n)
    {
        cin >> num[i];
    }
    solve();
    return 0;
}