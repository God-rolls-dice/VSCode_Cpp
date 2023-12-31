#include <bits/stdc++.h>
using namespace std;

int T;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int n;
        cin >> n;
        vector<int> change;
        int mid = (n - 1) / 2;
        long long ans(0);
        for (int i = 0; i <= mid; ++i)
        {
            char ch;
            cin >> ch;
            if (ch == 'L')
            {
                ans += i;
                change.emplace_back(n - 1 - 2 * i);
            }
            else
                ans += n - 1 - i;
        }
        for (int i = mid + 1; i < n; ++i)
        {
            char ch;
            cin >> ch;
            if (ch == 'R')
            {
                ans += n - 1 - i;
                change.emplace_back(2 * i - n + 1);
            }
            else
                ans += i;
        }
        sort(change.begin(), change.end(), [&](auto a, auto b)
             { return a > b; });
        int cSize = change.size();
        for (int k = 1; k <= n; ++k)
        {
            if (k <= cSize)
            {
                ans += change[k - 1];
                cout << ans << " ";
            }
            else
                cout << ans << " ";
        }
        cout << '\n';
    }

    return 0;
}