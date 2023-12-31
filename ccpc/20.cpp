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

/*
// 快速排序   hoare版本(左右指针法)
void QuickSort(vector<vector<ll>> &a, ll begin, ll end)
{
    // 只有一个数或区间不存在
    if (begin >= end)
        return;
    ll left = begin;
    ll right = end;
    // 选左边为key
    ll keyi = begin;
    while (begin < end)
    {
        // 右边选小   等号防止和key值相等    防止顺序begin和end越界
        while (a[end][0] >= a[keyi][0] && begin < end)
        {
            --end;
        }
        // 左边选大
        while (a[begin][0] <= a[keyi][0] && begin < end)
        {
            ++begin;
        }
        // 小的换到右边，大的换到左边
        swap(a[begin][0], a[end][0]);
        swap(a[begin][1], a[end][1]);
    }
    swap(a[keyi][0], a[end][0]);
    swap(a[keyi][1], a[end][1]);
    keyi = end;
    //[left,keyi-1]keyi[keyi+1,right]
    QuickSort(a, left, keyi - 1);
    QuickSort(a, keyi + 1, right);
}
 */

void BubbleSort(vector<vector<ll>> &a, ll n)
{
    int end = n;
    while (end)
    {
        int flag = 0;
        for (int i = 2; i <= end; ++i)
        {
            if (a[i - 1][0] > a[i][0])
            {
                swap(a[i - 1][0], a[i][0]);
                swap(a[i - 1][1], a[i][1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
        --end;
    }
}
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
    // sort(a.begin() + 1, a.end(), cmp_l);

    // QuickSort(a, 1, n);

    BubbleSort(a, n);
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
