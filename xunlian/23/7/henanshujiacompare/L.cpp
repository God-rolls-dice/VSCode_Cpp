#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n, m;
int a[1000005];
int tr[1000005];
int b[1000005];
int lowbit(int k)
{
    return k & -k;
}
void xi(int k, int w)
{
    while (k <= 1000000)
    {
        tr[k] += w;
        k += lowbit(k);
    }
}
int fin(int k)
{
    int cnt = 0;
    while (k)
    {
        cnt += tr[k];
        k -= lowbit(k);
    }
    return cnt;
}
// void build(int k,int l,int r){
//	if(l==r){
//		tr[k]=b[l];
//		return;
//	}
//	int mid=(l+r)/2;
//	build(k*2,l,mid);
//	build(k*2+1,mid+1,r);
//	tr[k]=tr[k*2]+tr[k*2+1];
// }
// void xi(int k,int l,int r,int to,int w){
//	if(l==r){
//		tr[k]+=w;
//		return;
//	}
//	int mid=(l+r)/2;
//	if(to<=mid)xi(k*2,l,mid,to,w);
//	else xi(k*2+1,mid+1,r)
// }
void solve()
{
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        xi(a[i], 1);
    }
    int temp = (n + 1) / 2;
    int t1, t2;
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld %lld", &t1, &t2);
        xi(a[t1], -1);
        a[t1] = t2;
        xi(t2, 1);
        int l = 1, r = 1000000;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (fin(mid) >= temp)
                r = mid;
            else
                l = mid + 1;
        }
        printf("%lld\n", l);
    }
}
signed main()
{
    T = 1;
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    // cin>>T;
    while (T--)
    {
        solve();
    }

    return 0;
}
