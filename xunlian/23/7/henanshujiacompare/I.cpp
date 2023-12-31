#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (auto i = (a); i >= (b); --i)
vector<int> num, num2;
const int N = 1e5 + 10;
ll n, temp, flag, num3[N];

void swap_1(int a, int b)
{
    swap(num2[num3[b]], num2[num3[a]]);
    swap(num3[b], num3[a]);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    FOR(i, 0, n - 1)
    {
        cin >> temp;
        num.push_back(temp);
        num3[temp] = i;
    }
    num2.resize(num.size()); // 添加这行代码以分配足够的空间
    copy(num.begin(), num.end(), num2.begin());
    sort(num.begin(), num.end());
    FOR(i, 0, n - 1)
    {
        if (num2[i] != num[i])
        {
            flag++;
            swap_1(num2[i], num[i]);
        }
    }
    cout << flag;
    return 0;
}
