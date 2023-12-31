#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int N, M, A, B, tp = 0;
    cin >> N >> M >> A >> B;
    unordered_map<int, int> moster;
    for (int i = 1; i <= M; i++)
    {
        cin >> tp;
        moster[tp]++;
    }
    vector<pair<int, int>> vec(moster.begin(), moster.end());
    sort(vec.begin(), vec.end(), [&](const auto& a, const auto& b){return a.second < b.second;});
    if (A <= B || B >= M)
    {
        cout << N;
        return; 
    }
    int ans = 0;
    tp = 0;
    while (1)
    {
        tp += (vec.begin() + ans)->second;
        ans ++;
        if (tp > B)
        {
            --ans;
            break;
        }
    }
    if ( (int)vec.size() - ans - (A - B) < 0)
    {
        cout << ans + N - vec.size();
    }
    else
    {
        cout << (int)vec.size() - ans - (A - B) + ans + N - vec.size();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
}