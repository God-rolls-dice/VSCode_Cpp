#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000 + 10;
int N, cnt, tp, n[24], ans;
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> cnt >> tp;
        for (int j = 0; j < 24; j++)
        { 
            if (tp >= 9 && tp < 18)
            {
                n[j] += cnt;
            }
            if (tp > 23)
            {
                tp %= 24;
            }
            tp++;
        }
    }
    for (int i = 0; i < 24; i++)
    {
        if (ans < n[i])
        {
            ans = n[i];
        }
    }

    cout << ans;
}