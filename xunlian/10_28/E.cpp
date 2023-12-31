#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string l, t;
    cin >> n >> l >> t;
    char a[n][n];
    memset(a, '.', sizeof(a));
    unordered_map<int, vector<int>> l_cnt, t_cnt;
    n = 3;
    if (l_cnt[1].size())
    {
        cout << 1;
    }
    else
    {
        cout << 2;
    }
}