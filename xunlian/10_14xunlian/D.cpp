#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<pdd> vpdd;
typedef vector<vd> vvd;

#define fi first
#define se second
#define ppb pop_back
#define pb push_back
#define pf push_front
#define qf pop_front
#define maxe max_element
#define mine min_element
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mset(x, a) memset(x, a, sizeof (x))
#define rep(i, l, r) for(ll i = l; i <= (r); ++ i)
#define per(i, r, l) for(ll i = r; i >= (l); -- i)
#define reps(i, l, r, d) for(ll i = l; i <= (r); i += d)
#define pers(i, r, l, d) for(ll i = r; i >= (l); i -= d)

template<class T> bool ckmax(T& a, T b) { return a < b ? (a = b, 1) : 0; }
template<class T> bool ckmin(T& a, T b) { return a > b ? (a = b, 1) : 0; }

const int N = 200005;

int n, m, q, tp, tp1, t[N], ans, w[25][2], f[N];
map<int, int> day;

void solve()
{
    cin >> n >> m >> q;
    rep (i, 1, q)
    {
        cin >> t[i];
        day[t[i] - t[i - 1] - 1]++;
    }
    day[n - t[q]]++;
    w[0][0] = 1;
    rep (i, 1, 20)
    {
        w[i][0] = w[i - 1][0] * 2;
    }
    rep (i, 1, m)
    {
        cin >> tp >> tp1;
        ckmax(w[tp][1], tp1);
    }
    for (auto i = day.begin(); i != day.end(); i++)
    {
        memset(f, 0, sizeof(f));
        for (int j = 0; w[j][0] <= i -> first; j++)
        {
            for (int l = w[j][0]; l <= i -> first; l++)
            {
                ckmax(f[l], f[l - w[j][0]] + w[j][1]);
            }
        }
        ans += f[i -> first] * i -> second;
    }
    cout << ans;
}

signed main() 
{
    ios
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}