#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int read()
{
    int x = 0, f = 1;
    char ch;
    for (ch = getchar(); (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
        ;
    if (ch == '-')
        f = -1, ch = getchar();
    do
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return x * f;
}

int n;
char s[N];
int cnt[27], tmp[27];
bool tag[N];
ll ans = 0;

deque<int> pos[N];
int a[N], tot;

struct BIT
{
    int tr[N];
    void add(int x)
    {
        while (x <= tot)
            tr[x] += 1, x += x & -x;
    }
    int sum(int x)
    {
        int res = 0;
        while (x)
            res += tr[x], x -= x & -x;
        return res;
    }
} T;

int main()
{
    n = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i)
        cnt[s[i] - 'a']++;
    for (int i = 0; i <= 26; ++i)
        tmp[i] = (cnt[i] / 2);
    int rtnum = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (tmp[s[i] - 'a']) // 判断有无这个字符
        {
            tag[i] = true; // 有tag[i]为true
            --tmp[s[i] - 'a'];
            ans += rtnum;
        }
        else
            ++rtnum;
    }
    //	for (int i = 0; i <= 26; ++i) tmp[i] = cnt[i];
    //	for (int i = 1; i <= n; ++i) printf("%d", tag[i]); puts("");
    int poscnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (tag[i])
        {
            //			--tmp[i];
            ++poscnt;
            pos[s[i] - 'a'].push_back(poscnt); // pos存储字符排序第几个去除中间没出现的
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!tag[i])
            a[++tot] = pos[s[i] - 'a'].front(), pos[s[i] - 'a'].pop_front();
    }
    //	puts("pas");
    //	for (int i = 1; i <= tot; ++i) printf("%d ", a[i]); puts("");
    for (int i = 1; i <= tot; ++i)
    {
        ans += T.sum(tot) - T.sum(a[i]);
        T.add(a[i]);
    }
    printf("%lld", ans);
    return 0;
}
