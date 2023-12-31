#include <bits/stdc++.h>
using namespace std;
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
#define mp make_pair
#define maxe max_element
#define mine min_element
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mset(x, a) memset(x, a, sizeof(x))
#define rep(i, l, r) for (ll i = l; i <= (r); ++i)
#define per(i, r, l) for (ll i = r; i >= (l); --i)
#define reps(i, l, r, d) for (ll i = l; i <= (r); i += d)
#define pers(i, r, l, d) for (ll i = r; i >= (l); i -= d)

template <class T>
bool ckmax(T &a, T b)
{
    return a < b ? (a = b, 1) : 0;
}
template <class T>
bool ckmin(T &a, T b) { return a > b ? (a = b, 1) : 0; }

void solve()
{
    int a[4][4], b[4][4] = {0};
    map<int, pii> c;
    int d[10];
    rep(i, 1, 9)
    {
        d[i] = i;
    }
    int tp = 0;
    rep(i, 1, 3)
    {
        rep(j, 1, 3)
        {
            cin >> a[i][j];
        }
    }
    rep(i, 1, 3)
    {
        if (a[i][1] == a[i][2])
        {
            a[(i - 1) * 3 + 1] = 
        }
    }

    int ans = 0;
    do
    {
        bool ok = true;
        REP1(i, 1, s.size())
        ok &= s[i] != s[i - 1];
        ans += ok;
    } while (next_permutation(all(s)));
};
int main()
{
    ios;
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}