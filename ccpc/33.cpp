#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int n, a, k, b, m;
        cin >> n;
        vector<int>h(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> h[i];
        }
        cin >> a >> k >> b;
        cin >> m;
        for (int i = 1; i <= n; i++)
        {
            if (h[i] + m * a <= k)
            {
                h[i] += m * a;
            }
            else
            {
                m = m - (k - h[i] + a - 1) / a;
                m = m % ((k - b + a - 1) / a);
                h[i] = b + m * a;
            }
        }
        for (int i = 1; i < n; i++)
        {
            cout << h[i];
        }
        cout << endl;
    }
}