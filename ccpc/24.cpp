#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll a, b, c;
    cin >> a >> b;
    if (gcd(a, b) > 1)
    {
        cout << 0;
        return 0;
    }
    if (a == 1 || b == 1)
    {
        cout << -1;
        return 0;
    }

    if (a < b)
    {
        swap(a, b);
    }
    a = a - b;
    if (a < b)
    {
        b = b - b / a * a;
    }
    c = a - b;
    if (b <= sqrt(a) && (int)sqrt(a) > 1)
    {
        for (int i = b; i <= sqrt(a); i++)
        {
            if (a % i == 0)
            {
                c = i - b;
                break;
            }
        }
    }
    if (b > sqrt(a))
    {
        for (int i = b; i < a; i++)
        {
            if (a % i == 0)
            {
                c = i - b;
                break;
            }
        }
    }
    cout << c;
}