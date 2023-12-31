#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 10;

int main()
{
    int n, m, tp;
    cin >> n >> m;
    unordered_map<int, int>num;
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> tp;
            num[tp] = i;
        }
    }
    for (auto i : num)
    {
            
    }

}