#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (auto i = (a); i >= (b); --i)
ll n, k, nu[2], ln, flag;
const int N = 1e6;
ll num[N];
char temp;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    FOR(i, 1, n)
    {
        cin >> temp;
        num[i] = temp - '0';
    }
    flag = num[1];
    for (int i = 1; i <= n; i)
    {

        nu[flag]++;
        ln = 0;
        while ((flag == num[i]) && (++ln <= k))
        {
            i++;
        }
        flag = num[i];
    }
    if (nu[0] == 1 || nu[1] == 1)
    {
        cout << "Alice";
    }
    else if ((nu[0] == 0 || nu[1] == 0) || (nu[0] == 2 && nu[1] == 2))
    {
        cout << "Bob";
    }
    else
    {
        cout << ":(";
    }
    cout << nu[0] << nu[1];
    return 0;
}