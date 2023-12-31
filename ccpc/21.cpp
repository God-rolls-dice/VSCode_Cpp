#include <bits/stdc++.h>
using namespace std;
#define int long long
#define foa(x, y, z) for (int x = (y), ooo = (z); x <= ooo; ++x)
#define fos(x, y, z) for (int x = (y), ooo = (z); x >= ooo; --x)
#define endl "\n"
#define sz(x) ((int)x.size())
#define pb push_back
#define fi first
#define se second
#define ct continue;

typedef pair<int, int> pii;

int ckmin(int &x, int y) { return x > y ? x = y, 1 : 0; }
int ckmax(int &x, int y) { return x < y ? x = y, 1 : 0; }

int n, m;
const int N = 1e6 + 10, inf = 0x3f3f3f3f3f3f3f3f;

int a[N], b[N];

void solve()
{
    cin >> n;
    foa(i, 1, n) cin >> a[i];
    vector<pii> v;
    foa(i, 1, n)
    {
        if (v.empty() || v.back().fi < a[i])
        {
            v.push_back({a[i], i});
        }
        auto p = lower_bound(v.begin(), v.end(), pii(a[i] + 1, 0));
        if (p != v.end())
        {
            b[p->se]++;
            b[i]--;
        }
    }
    foa(i, 1, n) b[i] += b[i - 1];
    int res = 0;
    foa(k, 1, n)
    {
        int ok = 1;
        for (int i = k; i <= n; i += k)
        {
            if (b[i])
            {
                ok = 0;
                break;
            }
        }
        res += ok;
    }
    cout << res << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    foa(i, 1, t)
    {
        solve();
    }
    return 0;
}
