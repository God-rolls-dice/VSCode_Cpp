#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (int i = (a); i >= (b); --i)
int N, M, K;

void Swap(vector<vector<int>> &map, int place)
{
    while ((place <= N - 1) && (map[place + 1][1] != map[place][1] && (map[place + 1][0] > map[place][0])))
    {
        swap(map[place], map[place + 1]);
        place++;
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> N >> M >> K;
    vector<int> price(K + 1, 0), flag(K + 1, 0);
    FOR(i, 1, M)
    cin >> price[i];
    vector<vector<int>> goods(N + 1, vector<int>(2, 0));
    FOR(i, 1, N)
    cin >> goods[i][0] >> goods[i][1];
    sort(goods.begin() + 1, goods.end(), [&](vector<int> a, vector<int> b)
         { return a[0] > b[0]; });
    for (int i = 1; i <= K;)
    {
        if (flag[goods[i][1]] == 0)
        {
            flag[goods[i][1]]++;
            goods[i][0] -= price[goods[i][1]];
            Swap(goods, i);
        }
        else
        {
            i++;
        }
    }
    ll sum = 0;
    FOR(i, 1, K)
    sum += goods[i][0];
    cout << sum;
}