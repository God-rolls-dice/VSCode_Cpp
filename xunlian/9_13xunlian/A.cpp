#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
ll end, l, r, ans;
typedef long long ll;
vector<ll> a(1, 0), idx(1, 0), sum(N, 0),  pdt(N, 1);

void dfs(int L, int R)
{
    ll tp;
    for (int i = L; i <= R; i += 2)
    {
        tp = max(pdt[R] / pdt[i], pdt[i]) + a[i + 1];
        if (pdt[R] / pdt[i - 2] < tp)
        {
            if (pdt[R] / pdt[i] > pdt[i])
            {
                l = pdt[i + 1] + 1;
                r = R;
                dfs(int l, int r);
                return;
            }
            else if (pdt[R] / pdt[i] < pdt[i])
            {
                l = L;
                r = pdt[i];
                dfs(int l, int r);
                return;
            }
            else
            {
                
            }
            
        }
    }
}
int main()
{
    freopen("E:\\Code\\Vision Studio Code\\C++\\iostream\\input.text", "r", stdin);
    freopen("E:\\Code\\Vision Studio Code\\C++\\iostream\\output.text", "w", stdout);
    int t;
    cin >> t;
    while (t --)
    {
        long long n, add = 0, mul = 1, temp;
        bool flag = 1;
        cin >> n;
        for (int i = 1; i <= n; i ++)
        {
            cin >> temp;
            if (i == 1)
            {
                if (temp == 1)
                {
                    flag = 0;
                }
            }
            if (temp == 1)
            {
                if (mul != 1)
                {
                    a.push_back(mul);
                    mul = 1;
                }
                add++;
            }
            else 
            {
                if (add)
                {
                    a.push_back(add);
                    add = 0;
                }
                mul *= temp;
            }
        }
        if(add)
        {
            a.push_back(add);
            add = 0;
        }
        else
        {
            a.push_back(mul);
            mul = 1;
        }
        ll num = a.size() - 2;
        l = 1, r = 1;
        ll tt;
        if (flag)
        {
            tt = 2;
        }
        else
        {
            tt = 3;
        }
        pdt[tt] = a[tt];
        for (int i = tt + 2; i <= num; i += 2)
        {
            end = i;
            pdt[i] = a[i] * pdt[i - 2];
        }
        for (int i = tt; i <= end; i ++)
        {
            sum[i] = sum[i - 1] + a[i];
        }
        if (sum[end] > pdt[end])
        {
            ans = sum[end];
            l = 1, r = 1;
        }
        else
        {
            ans = pdt[end];
            l = tt, r = end;
        }

        dfs(tt, end);
        cout << l << " " << r << endl;
    }
}
