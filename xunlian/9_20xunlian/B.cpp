#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a[26] = {0};
    int n = 0, cnt = 0;
    char tp;
    cin >> n;
    while (n --)
    {
        cin >> tp;
        if (a[tp - 'A'])
        {
            cnt ++;
        }
        else
        {
            a[tp - 'A'] ++;
            cnt += 2;
        }
    }
    cout << cnt << endl;
    
}
int main()
{
    int t ;
    cin >> t;
    while (t --)
    {
        solve();
    }
}