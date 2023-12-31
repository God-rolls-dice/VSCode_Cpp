#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (auto i = (a); i >= (b); --i)
int N, M;
long long MAX;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    vector<ll> L(N + 5, 0);
    FOR(i, 1, N)
    {
        cin >> L[i];
    }
    sort(L.begin(), L.end());
    vector<vector<ll>> A(*(L.end() - 1), vector<ll>(1, 0));
    int flag = 1;
    DEC(i, A.end() - 1, A.begin() + 1)
    {
        if (A[i])
    }
    return 0;
    for (auto x : L)
        ;
}
