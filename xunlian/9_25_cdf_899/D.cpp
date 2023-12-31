#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
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

int n, ans;
const int N = 2e5 + 10;
vector<vector<int>> vec(10, vector<int>(26 + 5, 0));
vector<int> tree[10];
vector<int> cnt(10, 0);

int dp(int i)
{
    int res = 1;
    if (tree[i].size()) 
    {
        if (cnt[i])
        for (auto k : tree[i])
        {
            if (cnt[k])
            {
                res += cnt[k];
            }
            else
            {
                res += dp(k);
            }
        }
        cnt[i] = res;
    }
    else
    {
        cnt[i] = res;
    }
    return cnt[i];
}

void dfs(int i, int chg)
{
    if (tree[i].size())
    {
        for (auto k : tree[i])
        {
            ans += k 
        }

    }

void solve()
{

    ll tp;
    cin >> n;
    rep (i, 1, n)
    {
        cin >> tp;
        rep (j, 0, 20)
        {
            vec[i][j] = tp % 2;
            tp = tp >> 1;
            if (!tp)
            {
                break;
            }
        }
    }
    int u, v;
    rep (i, 1, n - 1)
    {
        cin >> u >> v;
        tree[u].push_back(v);
    }
    rep (i, 1, n)
    {
        dp(i);
    }
}

signed main() 
{
    ios
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}