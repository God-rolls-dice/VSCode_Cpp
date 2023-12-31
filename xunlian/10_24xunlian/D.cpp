#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 300010;
// const int N = 10;
int X[N], Y[N], temp, ans, flag = 0;
vector<int> poi, tp;

signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> X[i] >> Y[i];
        if (X[i])
        {
            if (Y[i] > 0)
            {
                poi.emplace_back(i);
            }
            else
            {
                Y[i] = -INT_MAX;
            }
        }
    }
    if (poi.size() > 0)
    {
        for (int i = 1; i < poi[0]; i++)
        {
            if (Y[i] > 0)
            {
                ans += Y[i];
            }
        }
        for (int i = 1; i < poi.size(); i++)
        {
            for (int j = poi[i - 1] + 1; j < poi[i]; j++)
            {
                tp.emplace_back(Y[j]);
            }
            sort(tp.begin(), tp.end());
            if (tp.size())
            {
                if (tp.back() > 0)
                {
                    ans += Y[poi[i - 1]] + tp.back();
                    tp.pop_back();
                    Y[poi[i - 1]] = 0;
                }
                else
                {
                    if (Y[poi[i - 1]] > Y[poi[i]])
                    {
                        if (poi[i - 1] + tp.back() + Y[poi[i]] > poi[i - 1])
                        {
                            ans += Y[poi[i - 1]] + tp.back();
                        }
                        Y[poi[i]] = Y[poi[i - 1]];
                    }
                    else
                    {
                        if (poi[i - 1] + tp.back() + Y[poi[i]] > poi[i])
                        {
                            ans += Y[poi[i - 1]] + tp.back();
                        }
                    }
                }
                for (auto k : tp)
                {
                    if (k > 0)
                    {
                        ans += k;
                    }
                }
            }
            else
            {
                if (Y[poi[i - 1]] > Y[poi[i]])
                {
                    Y[poi[i] = poi[i - 1]];
                }
            }
            tp.clear();
        }
        ans += Y[poi.back()];
        for (int i = Y[poi.back()] + 1; i <= n; i++)
        {
            if (Y[i] > 0)
            {
                ans += Y[i];
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (X[i] == 0 && Y[i] > 0)
            {
                ans += Y[i];
            }
        }
    }
    cout << ans;
}
