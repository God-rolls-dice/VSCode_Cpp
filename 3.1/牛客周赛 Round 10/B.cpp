#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (auto i = (a); i >= (b); --i)

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int ans = 0;
    string s;
    cin >> s;
    bool flag = 1;
    sort(s.begin(), s.end());
    int n = s.size();
    do
    {
        flag = 1;
        FOR(i, 1, n - 1)
        if (s[i] == s[i - 1])
        {
            flag = 0;
            break;
        }
        if (flag)
        {
            ans++;
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << ans;
}