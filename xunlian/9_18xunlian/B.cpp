#include <bits/stdc++.h>
using namespace std;
string s1, s2;
vector<int> a0, a1;
void solve()
{
    bool flag = 1;
    cin >> s1 >> s2;
    int n = s1.size();
    for (int i = 0; i < n; i ++)
    {
        if (s1[i] == s2[i])
        {
            if ((s1[i] - '0') && flag)
            {
                cout << "YES" << endl;
                return;
            }
            else if (!(s1[i]-'0'))
            {
                a0.push_back(i);
                flag = 1;
            }
        }
        else
        {
            flag = 0;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t --)
    {
        solve();
    }
}
