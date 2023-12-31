#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (auto i = (a); i >= (b); --i)
const int N = 1e6 + 10;
int n, flag, max1, max2, temp2;
char temp;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    FOR(i, 1, n + 1)
    {
        if (i <= n)
        {
            cin >> temp;
        }
        else
        {
            temp = '0';
        }
        temp2 = flag;
        flag = (flag + 1) * (temp - '0');
        if ((temp2 >= max1) && (!flag))
        {
            if (temp2 >= max2)
            {
                max1 = max2;
                max2 = temp2;
            }
            else
            {
                max1 = temp2;
            }
        }
    }
    cout << max1 + max2;
    return 0;
}