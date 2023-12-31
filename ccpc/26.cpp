#include <bits/stdc++.h>
using namespace std;
int t, n;
char temp;
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<int> s_1(n, 0), s_2(n, 0), s_3(n, 0);
        int k1 = 0, k2 = 0, k3 = 0;
        string a[n], b[n], c[n];
        for (int k = 0; k < n; k++)
        {
            cin >> a[k];
        }
        for (int k = 0; k < n; k++)
        {
            cin >> b[k];
        }
        for (int k = 0; k < n; k++)
        {
            cin >> c[k];
        }

        for (int j = 0; j < n; j++)
        {
            for (int m = 0; m < n; m++)
            {
                if (a[j] == b[m])
                {
                    s_1[j]++, s_2[m]++;
                    break;
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int m = 0; m < n; m++)
            {
                if (a[j] == c[m])
                {
                    s_1[j]++, s_3[m]++;
                    break;
                }
            }
        }

        for (int j = 0; j < n; j++)
        {
            for (int m = 0; m < n; m++)
            {
                if (b[j] == c[m])
                {
                    s_2[j]++, s_3[m]++;
                    break;
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (s_1[j] == 0)
            {
                k1 += 3;
            }
            else if (s_1[j] == 1)
            {
                k1 += 1;
            }
            if (s_2[j] == 0)
            {
                k2 += 3;
            }
            else if (s_2[j] == 1)
            {
                k2 += 1;
            }
            if (s_3[j] == 0)
            {
                k3 += 3;
            }
            else if (s_3[j] == 1)
            {
                k3 += 1;
            }
        }
        cout << k1 << ' ' << k2 << ' ' << k3 << endl;
    }
    return 0;
}
