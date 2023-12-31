
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

const int N = 2010;
int n, m, goal, Map[N][N], sx, sy, ex, ey, cnt[N][N], sum[N][N], ans = 0x3f3f3f3f;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int sx, int sy)
{
    memset(cnt, 0x3f, sizeof(cnt));
    cnt[sx][sy] = 0;
    queue<array<int, 2>> q;
    q.push({sx, sy});
    while (q.size())
    {
        auto [hx, hy] = q.front();
        q.pop();
        if (Map[hx][hy] > goal)
        {
            sum[hx][hy] += cnt[hx][hy];
        }
        rep(i, 0, 3)
        {
            int nx = dir[i][0] + hx, ny = dir[i][1] + hy;
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m)
            {
                if (Map[nx][ny] != -1 && ckmin(cnt[nx][ny], cnt[hx][hy] + 1))
                {
                    q.push({nx, ny});
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> goal;
    cin >> sx >> sy >> ex >> ey;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> Map[i][j];
        }
    }
    bfs(sx, sy);
    bfs(ex, ey);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (sum[i][j])
            {
                ckmin(ans, sum[i][j]);
            }
        }
    }
    if (ans == 0x3f3f3f3f)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}

signed main()
{
    ios int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}