#include <bits/stdc++.h>
#define sq(x) (1ll * (x) * (x))
#define cei(a, b) ((-1ll + (a) + (b)) / (b))
#define bug(x) cerr << #x << " = " << x << '\n'
#define fi first
#define se second
#define pb emplace_back
#define chkmin(a, b) ((a > b) ? (a = b, true) : false)
#define chkmax(a, b) ((a < b) ? (a = b, true) : false)
using namespace std;
using ll = long long;
typedef pair<ll, ll> pii;
mt19937 rnd((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
int getrand(int min, int max) { return rnd() % (max - min + 1) + min; }
// unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
// shuffle(v.begin(),v.end(),std::default_random_engine(seed));
// const int inf = 0x3f3f3f3f;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int mod = 998244353;
int fpow(int a, int n = mod - 2)
{
    int base = a;
    int res = 1;
    while (n)
    {
        if (n & 1)
            res = 1ll * base * res % mod;
        base = 1l * base * base % mod;
        n >>= 1;
    }
    return res;
}
const int N = 1E6 + 5;
int n, m, k, q, t;
ll sq[N];
ll cal1(ll a, ll b)
{
    ll ans = 0;
    while (a <= b / 2)
    {
        if (b & 1)
            ans++;
        b /= 2;
        ans++;
    }
    return ans + b - a;
}
ll sqr(ll x)
{
    ll r = sqrt(x);
    while (sq(r) > x)
        r--;
    while (sq(r + 1) <= x)
        r++;
    return r;
}

ll solve(ll a, ll b)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(pii(0, b));
    ll res = inf;
    while (!q.empty())
    {
        auto [cnt, x] = q.top();
        q.pop();
        chkmin(res, x - a + cnt);
        if (x == a)
            return res;
        ll nxt = x / 2;
        if (nxt >= a)
        {
            q.push(pii((x & 1) + cnt + 1, nxt));
        }
        nxt = sqr(x);
        if (nxt >= a)
        {
            q.push(pii(cnt + 1 + (x - sq(nxt)), nxt));
        }
    }
    return res;
}
void solve()
{
    for (int i = 1; i < N; i++)
        sq[i] = sq(i);
    scanf("%d", &q);
    while (q--)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        printf("%lld\n", solve(a, b));
    }
    return;
}
int main()
{
#ifdef HAMMER
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    // sync_with_stdio(false);
    // cin.tie(nullptr);
    int T = 1;

    // scanf("%d", &T);

    // while (~scanf("%d%d", &n, &m))
    for (int i = 1; i <= T; i++)
    {
        // printf("Case #%d: ",i);
        solve();
    }
#ifdef HAMMER
    fprintf(stderr, "exit after %ld ms\n", clock());
#endif
    return 0;
}
