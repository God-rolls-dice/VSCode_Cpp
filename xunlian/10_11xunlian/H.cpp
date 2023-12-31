#include<bits/stdc++.h>
#include <deque>
#define N 777
#define mod 998244353
using namespace std;
long long n;
int m, sz, tre[N][2], fail[N], sum;
char s[9];
bool ban[N];
struct matrix
{
    int a[N][N];
    inline void operator*=(const matrix &kkk)
    {
        int ans[N][N] = {};
        for (int i = 0; i <= sz; ++i)
            for (int j = 0; j <= sz; ++j)
                if (a[i][j])
                    for (int k = 0; k <= sz; ++k)
                        ans[i][k] = (ans[i][k] + (long long)(a[i][j]) * kkk.a[j][k]) % mod;
        for (int i = 0; i <= sz; ++i)
            for (int j = 0; j <= sz; ++j)
                a[i][j] = ans[i][j];
    }
} a, ans;
main()
{
    scanf("%lld%d", &n, &m);
    for (int j; m--;)
    {
        scanf("%s", s);
        j = 0;
        for (int i = 0; s[i]; j = tre[j][s[i++] != 'a'])
            if (!tre[j][s[i] != 'a'])
                tre[j][s[i] != 'a'] = ++sz;
        ban[j] = 1;
    }
    fail[tre[0][0]] = fail[tre[0][1]] = 0;
    deque<int> q;
    if (tre[0][0])
        q.emplace_back(tre[0][0]);
    if (tre[0][1])
        q.emplace_back(tre[0][1]);
    for (int i; q.size();)
    {
        i = q.front();
        q.pop_front();
        ban[i] |= ban[fail[i]];
        if (tre[i][0])
            fail[tre[i][0]] = tre[fail[i]][0],
            q.emplace_back(tre[i][0]);
        else
            tre[i][0] = tre[fail[i]][0];
        if (tre[i][1])
            fail[tre[i][1]] = tre[fail[i]][1],
            q.emplace_back(tre[i][1]);
        else
            tre[i][1] = tre[fail[i]][1];
    }
    for (int i = 0; i <= sz; ++i)
        if (!ban[i])
            ++a.a[i][tre[i][0]], ++a.a[i][tre[i][1]];
    ans.a[0][0] = 1;
    for (; n; n >>= 1, a *= a)
        if (n & 1)
            ans *= a;
    for (int i = 0; i <= sz; ++i)
        if (!ban[i])
            sum = (sum + ans.a[0][i]) % mod;
    printf("%d", sum);
}
