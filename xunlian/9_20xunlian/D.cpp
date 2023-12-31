#include <bits/stdc++.h>
using namespace std;
int n;
string s;

void solve()
{
    unordered_map<string, bool> Map;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        Map[s[i]] = true;
    }
    for (int i = 0; i < n; ++i)
    {
        bool flag = 0;
        for (int j = 1; j < s[i].size(); ++j)
        {
            string s1 = s[i].substr(0, j);
            string s2 = s[i].substr(j);
            if (Map[s1] && Map[s2])
            {
                flag = 1;
                break;
            }
        }
        cout << flag;
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}