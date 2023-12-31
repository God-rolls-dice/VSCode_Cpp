#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long T, a, b;
void solve(ll a, ll b)
{
    ll temp_a = 0, temp_b = 0;
    temp_a = a % 3;
    temp_b = b % 3;
    if ((min(temp_a, temp_b) == 0) || (max(temp_a, temp_b) == 1))
    {
        cout << "niumei" << endl;
    }
    else
    {
        cout << "niuniu" << endl;
    }
}

int main()
{
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    for (ll i = 1; i <= T; i++)
    {
        cin >> a >> b;
        solve(a, b);
    }
}