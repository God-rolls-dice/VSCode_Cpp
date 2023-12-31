// 这回只花了114514min就打完了。
// 真好。记得多手造几组。ACM拍什么拍。
#include "bits/stdc++.h"
using namespace std;
template <typename T1, typename T2>
istream &operator>>(istream &cin, pair<T1, T2> &a) { return cin >> a.first >> a.second; }
template <typename T1>
istream &operator>>(istream &cin, vector<T1> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename T1>
istream &operator>>(istream &cin, valarray<T1> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &cout, const pair<T1, T2> &a) { return cout << a.first << ' ' << a.second; }
template <typename T1, typename T2>
ostream &operator<<(ostream &cout, const vector<pair<T1, T2>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename T1>
ostream &operator<<(ostream &cout, const vector<T1> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
template <typename T1, typename T2>
bool cmin(T1 &x, const T2 &y)
{
    if (y < x)
    {
        x = y;
        return 1;
    }
    return 0;
}
template <typename T1, typename T2>
bool cmax(T1 &x, const T2 &y)
{
    if (x < y)
    {
        x = y;
        return 1;
    }
    return 0;
}
template <typename T1>
vector<T1> range(T1 l, T1 r, T1 step = 1)
{
    assert(step > 0);
    int n = (r - l + step - 1) / step, i;
    vector<T1> res(n);
    for (i = 0; i < n; i++)
        res[i] = l + step * i;
    return res;
}
template <typename T1>
basic_string<T1> operator*(const basic_string<T1> &s, int m)
{
    auto r = s;
    m *= s.size();
    r.resize(m);
    for (int i = s.size(); i < m; i++)
        r[i] = r[i - s.size()];
    return r;
}
#if !defined(ONLINE_JUDGE) && defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef double db;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
// template<typename T1,typename T2> void inc(T1 &x,const T2 &y) { if ((x+=y)>=p) x-=p; }
// template<typename T1,typename T2> void dec(T1 &x,const T2 &y) { if ((x+=p-y)>=p) x-=p; }
const int N = 1e6 + 5;
int dis[N];
ll cal(ll a, ll b)
{
    // cerr<<a<<' '<<b;
    ll ans = 0;
    int wa = __lg(a), wb = __lg(b);     //找到a, b的二进制第一个一的位置
    if (a << wb - wa > b)   //a和b的二进制最高位对齐，如果a>b
    {
        ans += (1ll << wa + 1) - a;     //把a二进制再进一位需要加多少
        a = 1ll << wa + 1;  //a二进制进一位的值
        ++wa;   //a二进制最高位加1
    }
    ans += (b >> wb - wa) - a;  //现在a是wa位下最小的值，此时将b降位与a相减值一定大于零，ans加上b降维后，a化成b需要加多少
    wb -= wa;   //需要降位的值
    ans += wb + __builtin_popcountll((1ll << wb) - 1 & b);  //b的二进制wb后随着进wb位加1
    // cerr<<" = "<<ans<<endl;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(15);
    int T;
    cin >> T;
    while (T--)
    {
        ll a, b, i, j;
        cin >> a >> b;
        ll ans = cal(a, b);
        if (a < N)
        {
            memset(dis, 0x3f, sizeof dis);
            dis[a] = 0;
            for (i = a; i * i <= b; i++)
            {
                if (i + 1 < N)
                    cmin(dis[i + 1], dis[i] + 1);
                if (i * 2 < N)
                    cmin(dis[i * 2], dis[i] + 1);
                if (i * i < N)
                    cmin(dis[i * i], dis[i] + 1);
                if (dis[i] + 1 < ans)
                {
                    cmin(ans, dis[i] + 1 + cal(i * i, b));
                }
            }
            // dbg(dis[10000]);
        }
        cout << ans << '\n';
    }
}
