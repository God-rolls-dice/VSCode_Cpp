#include <bits/stdc++.h>
using namespace std;
int N, Q;
struct aaaa{
    char a[10];
}b;
void solve()
{
    b = {"abc"};
    cout << b.a;
    cout << sizeof b.a;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
}