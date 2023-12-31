#include <bits/stdc++.h>
using namespace std;
int t = 0;
int pd(vector<long long> a)
{
    if (a[5] >= a[4] + a[3])
    {
        return 0;
    }
    for (int i = 1; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            if (a[0] + a[i] > a[j] && a[j] - a[0] < a[i])
            {
                int x = 0, y = 0, z = 0;
                for (int k = 1; k < 6; k++)
                {
                    if (k != i && k != j)
                    {
                        if (!x)
                        {
                            x = k;
                        }
                        else if (!y)
                        {
                            y = k;
                        }
                        else
                        {
                            z = k;
                        }
                    }
                }
                if (x + y > z && z - y < x)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    int pd(vector<long long> a);
    long long temp = 0;
    cin >> t;
    vector<vector<long long>> a(t);
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> temp;
            a[i].push_back(temp);
        }
        sort(a[i].begin(), a[i].end());
    }
    for (int i = 0; i < t; i++)
    {
        if (pd(a[i]))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
  
}