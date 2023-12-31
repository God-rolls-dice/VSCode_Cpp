#include <bits/stdc++.h>
using namespace std;
int t;
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> t;
    for (int l = 0; l < t; ++l)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int flag = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
            {
                if (!((a[i] == 'G' && b[i] == 'B') || (a[i] == 'B' && b[i] == 'G')))
                {
                    cout << "NO" << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << "YES";
        }
    }

    return 0;
}
