#include <bits/stdc++.h>
using namespace std;
map<string, int> num;
int N;
long long ans;
string tp, C;

int Compare(string s1, string s2)
{
    if (s1.length() > s2.length())
    {
        return 1;
    }
    else if (s1.length() < s2.length())
    {
        return -1;
    }
    else
    {
        return s1.compare(s2);
    }
}

void Sub(string& s1, string& s2)
{
    int n = s2.length(), j = s1.length() - 1;
    for (int i = n - 1; i >= 0; i--, j--)
    {
        if (s1[j] >= s2[i])
        {
            s1[j] = s1[j] - s2[i] + '0';
        }
        else
        {
            s1[j] = s1[j] + 10 - s2[i] + '0';
            s1[j - 1] -= 1;
        }
    }
    while (j >= 0 && s1[j] < '0')
    {
        s1[j] += 10;
        j --;
        s1[j] --;
    }
    while (s1[0] == '0')
    {
        s1.erase(s1.begin());
    }
}

void solve()
{ 
    cin >> N >> C;
    for (int i = 1; i <= N; i++)
    {
        cin >> tp;
        num[tp]++;
    }
    for (auto nx : num)
    {
        int flag = Compare(nx.first, C);
        if(flag > 0)
        {
            string s1 = nx.first, s2 = C;
            Sub(s1, s2);
            if (num.find(s1) != num.end())
            {
                ans += ((long long)num.find(s1) -> second) * (nx.second);
            }
        }
        else if (flag == 0)
        {
            if (num.find("0") != num.end())
            {
                ans += (num.find("0")->second) * (nx.second);
            }
        }
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
}