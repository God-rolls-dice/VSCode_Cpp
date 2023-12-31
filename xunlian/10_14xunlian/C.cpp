#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

signed main()
{
    int n, k;
    cin >> n >> k;
    int h[n];
    for (auto &x : h)
    {
        cin >> x;
    }
    sort(h, h + n);
    int l = 0, r = h[n - 1] - h[0];
    while (l < r)
    {
        int mid = (l + r) / 2;
        int begin = h[0], cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (h[i] - begin > mid)
            {
                begin = h[i];
                cnt++;
            }
        }
        if (cnt <= k)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l;
}