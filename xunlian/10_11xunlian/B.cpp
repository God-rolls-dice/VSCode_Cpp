#include <bits/stdc++.h>
using namespace std;
#define int long long
map<char, int> Map;
void solve()
{
    Map['A'] = 0;
    Map['B'] = 3;
    Map['C'] = 4;
    Map['D'] = 8;
    Map['E'] = 9;
    Map['F'] = 14;
    Map['G'] = 23;
    char c1, c2;
    cin >> c1 >> c2;
    cout << Map[max(c1, c2)] - Map[min(c1, c2)];
}

signed main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}