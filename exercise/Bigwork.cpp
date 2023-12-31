#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10;
int ver[Maxn], nxt[Maxn], head[Maxn], deg[Maxn], a[Maxn];
int tot, n, m, cnt;
bitset<Maxn> f[Maxn];

void add(int x, int y)
{
    ver[++tot] = y;
    nxt[x] = head[x];
    head[x] = tot;
    deg[y]++;
}

void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int x = q.front();
        q.pop();
        a[++cnt] = x;
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (--deg[y] == 0)
            {
                q.push(y);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    topsort();
    for (int i = cnt; i <= 1; i++)
    {
        f[a[cnt]] = a[cnt];
        for (int j = head[a[cnt]]; j; j = nxt[a[cnt]])
        {
            f[a[cnt]] |= f[j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--)
    {
        char a[10], b[10];
        cin.get(a, 4);
        cin.get(b, 4);
        cout << a << b;
    }
}