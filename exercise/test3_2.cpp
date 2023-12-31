#include <bits/stdc++.h>
using namespace std;
#define foa(i, a, b) for (int i = a; i < b; i++)
int main()
{
    auto = 
    int n, m;
    cin >> n >> m;
    int a[n] = {0};
    foa(i, 0, n) cin >> a[i];
    sort(a, a + n, greater<int>());
    sort(a, a + m, [](int x, int y)
         { auto calc = [](int v)
           {
               int res = 0;
               while (v)
               {
                   res += v % 10;
                   v /= 10;
               }
               return res;
           } ;
           return (calc(x) < calc(y)); });
    foa(i, 0, m) cout << a[i] << " ";
}