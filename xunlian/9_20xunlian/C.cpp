#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, tp;
    cin >> n;
    vector<int> vec(1, 0);
    for (int i =  1; i <= n; i ++)
    {
        cin >> tp;
        vec.push_back(tp);
    }
    for (int i = 1; i <= n; i ++)
    {
        cin >> tp;
        string s;
        cin >> s;
        tp = 0;
        for (auto i : s)
        {
            if (i == 'U')
            {
                tp --;
            }
            else
            {
                tp ++;
            }
        }
        tp = tp % 10;
        vec[i] = (vec[i] + tp + 10 ) % 10;
        cout << vec[i] << ' ';
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}