#include <iostream>
#include <algorithm>
#include <cassert>

#define int long long

using namespace std;

const int N = 40010;
const int inf = 1e15;

struct Node
{
    int l, r, val;
} tr[N * 1000];
int n, m;
int a[N];
int root[N], idx;

inline int lowbit(int x)
{
    return x & -x;
}

inline void insert(int &p, int l, int r, int x, int c)
{
    if (!p)
        p = ++idx;
    tr[p].val += c ;
    if (l == r)
        return;
    int mid = l + r >> 1;
    if (x <= mid)
        insert(tr[p].l, l, mid, x, c);
    else
        insert(tr[p].r, mid + 1, r, x, c);
}

inline int query(int p, int l, int r, int ql, int qr)
{
    if (!p)
        return 0;
    if (l >= ql && r <= qr)
        return tr[p].val;
    int mid = l + r >> 1, res = 0;
    if (ql <= mid)
        res += query(tr[p].l, l, mid, ql, qr);
    if (qr > mid)
        res += query(tr[p].r, mid + 1, r, ql, qr);
    return res;
}

inline void add(int pos, int val, int v)
{
    for (int i = pos; i <= n; i += lowbit(i))
        insert(root[i], 1, inf, val, v);
}

inline int ask(int l, int r, int ql, int qr)
{
    if (l > r || ql > qr)
        return 0;
    int res = 0;
    for (r; r; r -= lowbit(r))
        res += query(root[r], 1, inf, ql, qr);
    for (--l; l; l -= lowbit(l))
        res -= query(root[l], 1, inf, ql, qr);
    return res;
}

signed main()
{
    cin >> n >> m;
    assert(n <= 40000);
    assert(m <= 40000);
    for (int i = 1; i <= n; i++)
        cin >> a[i], assert(a[i] > 0 && a[i] <= 1000000000);
    for (int i = 1; i <= n; i++)
        add(i, a[i], a[i]);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int k, y;
            cin >> k >> y;
            assert(k);
            assert(y > 0);
            assert(y <= 1000000000);
            add(k, a[k], -a[k]);
            add(k, a[k] = y, y);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int last = 0, res = 0;
            int times = 0;
            while (true)
            {
                ++times;
                assert(times <= 60);
                int sum = ask(l, r, last + 1, res + 1);
                if (sum)
                    last = res + 1, res += sum;
                else
                    break;
            }
            cout << res + 1 << '\n';
        }
    }
    return 0;
}