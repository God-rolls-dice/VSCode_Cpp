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
    int n, ans = 0, num = 1, max = 1;
    cin >> n;
    char c1, c2;
    cin >> c1;
    rep(i, 2, n)
    {
        cin >> c2;
        if (c2 == c1)
        {
            num ++;
            if (max < num)
            {
                max = num;
            }
        }
        else
        {
            num = 1;
        }
        c1 = c2;
    }
    ans = max + 1;
    cout << ans << endl;
}

int main()
{
    ios int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}