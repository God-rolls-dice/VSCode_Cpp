#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (auto i = (a); i >= (b); --i)
ll n, MIN;
vector<ll> w;
vector<ll> d;
vector<ll> sum_d;
vector<ll> sum_w;
vector<ll> Left;
vector<ll> Right;
vector<vector<ll>> mid_left;
vector<vector<ll>> mid_right;
// vector<vector<ll>> R_mid;
void dp(ll left, ll right, ll sum);
int sum2 = 0;

int main()
{
    void move_left(ll left, ll right, ll sum);
    void move_right(ll left, ll right, ll sum);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    w = vector<ll>(n + 5, 0);
    d = vector<ll>(n + 5, 0);
    sum_d = vector<ll>(n + 5, 0);
    sum_w = vector<ll>(n + 5, 0);
    Left = vector<ll>(n + 5, 0);
    Right = vector<ll>(n + 5, 0);
    mid_left = vector<vector<ll>>(n + 5, vector<ll>(n + 5, 0));
    mid_right = vector<vector<ll>>(n + 5, vector<ll>(n + 5, 0));
    DEC(i, n, 1)
    {
        cin >> w[i];
        cin >> d[i];
    }
    FOR(i, 1, n)
    {
        sum_d[i] = sum_d[i - 1] + d[i]; // 保存0-i的距离
        sum_w[i] = sum_w[i - 1] + w[i]; // 保存0-i的权值之和
    }
    ll left = 1, right = n, sum = 0;
    FOR(i, 2, n - 1)
    {
        sum = sum + (sum_d[i] - sum_d[1]) * w[i]; // 计算服务点在1，n时所需的总共代价
    }
    MIN = sum;            // 令1，n位当前价值最小的方案
    dp(left, right, sum); // 递归遍历
    cout << MIN << endl;
}
void move_left(ll left, ll right, ll sum)
{

    if (Left[left] == 0)
    {
        Left[left] = sum_d[left] * w[left]; // 计算left向左移时left右边所增加的代价，并保存下来，下次遇到不用计算
    }
    mid_left[left][right] = d[left + 1] * (sum_w[right - 1] - sum_w[left]); // 计算left向右移时left右边边所增加的代价，并保存下来，下次遇到不用计算
    sum = sum + Left[left] - mid_left[left][right];                         // 计算移动后总代价
    left++;
    if (sum < MIN)
    {
        MIN = sum; // 求出此时的最小代价
    }

    if (left + 1 < right) // 看能否在往右移动
    {
        if (mid_left[left][right]) // 看下面的情况是否遇到过，遇到就直接跳过
            return;
        dp(left, right, sum); // 再次递归
    }
}
void move_right(ll left, ll right, ll sum)
{

    if (Right[right] == 0) // 计算right向左移时left左边所增加的代价，并保存下来，下次遇到不用计算
    {
        Right[right] = d[right] * (sum_w[n] - sum_w[right - 1]);
    }
    mid_right[left][right] = w[right - 1] * (sum_d[right - 1] - sum_d[left]); // 计算right向右移时left右边边所增加的代价，并保存下来，下次遇到不用计算
    sum = sum + Right[right] - mid_right[left][right];                        // 计算移动后总代价
    right--;
    if (sum < MIN)
    {
        MIN = sum; // 求出此时的最小代价
    }

    if (left + 1 < right) // 看能否在往左移动
    {
        if (mid_left[left][right])
            return;
        dp(left, right, sum); // 再次递归
    }
}

void dp(ll left, ll right, ll sum)
{

    move_left(left, right, sum); // left向右移动
    if (mid_right[left][right])  // 看向左移动时是否计算过这种情况
    {
        return;
    }
    move_right(left, right, sum); // right向左移动
}
