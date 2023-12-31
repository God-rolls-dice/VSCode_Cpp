
#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
    cin >> s;
    int temp;
    for (int i = 0; i <= 9; i++)
    {
        temp = s[i] - '0';
        if (temp == 3)
        {
            cout << 31 << endl;
            break;
        }
        else if (temp == 1)
        {
            cout << 13 << endl;
            break;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}