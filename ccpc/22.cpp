#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long k = 0;
bool cmp_l(const vector<ll> &a, const vector<ll> &b)
{
    return a[0] < b[0];
}
// int pd(ll begin, vector<ll> b, ll sum_1)
// {
//     ll sum_2 = 0;
//     if (2 * (begin + 1) >= b.size())
//     {
//         k++;
//         return 0;
//     }
//     for (ll i = begin + 1; i < b.size(); i++)
//     {
//         sum_2 += b[i];
//         if (sum_2 == sum_1)
//         {
//             sum_2 = 0;
//         }
//         else if (sum_2 > sum_1)
//         {
//             return 0;
//         }
//     }
//     k++;
//     return 0;
// }
int main()
{
    ll n;
    ll temp = 0;
    ll max = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<vector<ll>> a(n + 1);
    vector<ll> b(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        cin >> temp;
        a[i].push_back(temp);
        a[i].push_back(i);
    }
    // sort(a.begin(), a.end(), [](const vector<ll> &a, const vector<ll> &b)
    //      { return a[0] < b[0]; });
    sort(a.begin() + 1, a.end(), cmp_l);
    // if (a[1][1] == a.size() - 1)
    // {
    //     cout << 1;
    //     return 0;
    // }
    // if (a[1][1] == a.size() - 2)
    // {
    //     cout << 2;
    //     return 0;
    // }
    ll end = 0;
    for (ll i = 1; i <= n; i = end + 1)
    {
        end = a[i][1];
        for (ll j = i; j <= end; j++)
        {
            if (a[j][1] > end)
            {
                end = a[j][1];
            }
        }
        b[end]++;
        if (max < end - i + 1)
        {
            max = end - i + 1;
        }
    }
    ll begin = 0;
    ll sum_1 = 0;
    for (ll i = max; i <= n; i++)
    {
        int ok = 1;
        for (ll j = i; j <= n; j += max)
        {
            if (!b[j])
            {
                ok = 0;
                break;
            }
        }
        k += ok;
    }
    // for (ll i = begin; i < b.size(); i++)
    // {
    //     pd(begin, b, sum_1);
    // }
    cout << k;
}
