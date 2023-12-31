#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll mod = 101;
    ll n, m, k;
    string s;
    vector<ll> hash(1, 0);
    vector<ll> cge(1, 0);
    map<ll, ll> cnt;
    map<ll, ll> last;
    cin >> n >> m >> k >> s;
    ll num = s.size();
    for (int i = 1; i <= num; i++)
    {
        hash.push_back((hash[i - 1] * 10 + s[i - 1]) % mod);
    }
    int flag = 0;
    for (int i = 1; i <= n - m + 1; i++)
    {
        ll temp = ((hash[i + m - 1] - hash[i - 1] * (ll)pow(10, m)) % mod + mod) % mod;
        if (last[temp] + m - 1 >= i && last[temp])
            continue;
        last[temp] = i;
        cnt[temp]++;
    }
    for (auto tt : cnt)
    {
        if (tt.second == k)
            flag++;
    }
    cout << flag;
}