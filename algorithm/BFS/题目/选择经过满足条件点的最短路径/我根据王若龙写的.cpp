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
template <class t, class u>
bool ckmin(t &a, u b) { return (a > b) ? a = b, true : false; }

const int N = 2010;
int n, m, k, sx, sy, wx, wy, Map[N][N];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int f[N][N][2];

void bfs(int sx, int sy)
{
    queue<array<int, 3>> q;
    q.push({sx, sy});
    while (q.size())
    {
        auto[nx, ny, nflag] = q.front();
        q.pop();
        if (nflag && nx == wx && ny == wy)
        {
            cout << f[nx][ny][nflag];
            return;
        }
        for (int i = 0; i <= 3; i++)
        {
            int x = nx + dir[i][0], y = ny + dir[i][1];
            if (1 <= x && x <= n && 1 <= y && y <= m)
            {
                int flag = nflag;

                if (Map[x][y] > k)
                {
                    flag = 1;       //当遇到符合点应该按终点到这里的最短距离来算
                }
                if (Map[x][y] != -1 && ckmin(f[x][y][flag], f[nx][ny][nflag] + 1))  //如果这时flah = 1
                // 那么f[x][y][flag]都为最大值一定能满足条件与起点和终点分别BFS到满足k的点相同
                {
                    q.push({x, y, flag});
                }
            }
        }
    }
    cout << -1;
}

void solve()
{
    cin >> n >> m >> k;
    cin >> sx >> sy >> wx >> wy;
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> Map[i][j];
        }
    }
    f[sx][sy][0] = 0;
    bfs(sx, sy);
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