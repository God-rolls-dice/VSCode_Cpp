#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int a[64] = {0}, p[64] = {0}, temp[64] =  {0}, ans, flag = 0;

void Add(int ans[20], int a)
{
    for (int i = 0; a; i++)
    {
        ans[i] += a % 10;
        if  (ans[i] / 10)
        {
            ans[i + 1] += 1;
            if (i + 1 > flag)
            {
                flag = i + 1;
            }
            ans[i] %= ans[i];
        }
        a /= 10;
        if (i > flag)
        {
            flag = i;
        }
    }
}

signed main()
{
    
    p[0] = 1;
    for (int &i : a)
    {
        cin >> i;
    }
    for (int i = 1; i <= 63; i++)
    {
        p[i] = p[i - 1] * 2;
    }
    for (int i = 0; i <= 63; i++)
    {
        ans += p[i] * a[i];
    }
    cout << ans;
    //     Add(ans, p[i] * a[i]);
    // }
    // for (int i = 0; i <= flag; i++)
    // {
    //     cout << a[i];
    // }
}
