#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const int n = 2e5 + 10;
const ll MOD = 998244353;
int q, l, r, i = 1;
int w, a[n];
bool flag;

struct SegmentTree
{
    int l, r;
    ll sum, add, extrai, extras;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
    #define exti(x) tree[x].extrai
    #define exts(x) tree[x].extras
} tree[n * 4];

void build(int p, int l, int r)
{
    l(p) = l, r(p) = r;
    if (l == r)
    {
        sum(p) = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    sum(p) = (sum(2 * p) + sum(2 * p + 1)) % MOD;
}

void spread(int p)
{
    if (add(p))
    {
        sum(2 * p) = (sum(2 * p) + ((r(p * 2) - l(p * 2)) + 1) * add(p)) % MOD;
        exts(2 * p) = (exts(2 * p) + exti(p) * (r(p * 2) - l(p * 2) + 1)) % MOD;
        sum(2 * p + 1) = (sum(2 * p + 1) + (r(p * 2 + 1) - l(p * 2 + 1) + 1) * add(p)) % MOD;
        exts(2 * p + 1) = (exts(2 * p + 1) + exti(p) * (r(p * 2 + 1) - l(p * 2 + 1) + 1)) % MOD;
        add(2 * p) = (add(2 * p) + add(p)) % MOD;
        add(2 * p + 1) = (add(2 * p + 1) + add(p)) % MOD;
        exti(2 * p + 1) += exti(p);
        exti(2 * p) += exti(p);
        add(p) = 0;
        exti(p) = 0;
    }
}

void change(int p, int l, int r, ll d)
{
    if ((l <= l(p)) && (r >= r(p)))
    {
        sum(p) += d * (r(p) - l(p) + 1);
        exts(p) += d * (i - 1) * (r(p) - l(p) + 1);
        exti(p) += d * (i - 1);
        add(p) = add(p) + d;
        return;
    }
    spread(p);
    int mid = (l(p) + r(p)) / 2;
    if (l <= mid)
        change(p * 2, l, r, d);
    if (r > mid)
        change(p * 2 + 1, l, r, d);
    sum(p) = sum(p * 2) + sum(p * 2 + 1);
    exts(p) = exts(p * 2) + exts(p * 2 + 1);
}

ll ask(int p, int l, int r)
{
    if ((l <= l(p)) && (r >= r(p)))
    {
        return (sum(p) * i - exts(p) + MOD) % MOD;
    }
    spread(p);
    int mid = (l(p) + r(p)) / 2;
    ll val = 0;
    if (l <= mid)
        val = (val + ask(p * 2, l, r)) % MOD;
    if (r > mid)
        val = (val + ask(p * 2 + 1, l, r)) % MOD;
    return val;
}

int main()
{
    int flag = 0;
    cin >> flag >> q;
    build(1, 1, flag);
    for (i = 1; i <= q; i ++)
    {
        cin >> flag >> l >> r;
        if (flag)
        {
            cout << ask(1, l, r) % MOD << endl;
        }
        else
        {
            cin >> w;
            w = w % MOD;
            change(1, l, r, w);
        }
    }
    return 0;
}