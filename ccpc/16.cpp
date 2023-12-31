#include <bits/stdc++.h>
using namespace std;

bool cmp_l(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}
int search_min(vector<vector<int>> fa, int size, int target) // 找到第一个小于他的数
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {                                             // 当left == right时，区间[left, right]仍然有效
        int middle = left + ((right - left) / 2); // 等同于 (left + right) / 2，防止溢出
        if (fa[middle][0] > target)
        {
            if (fa[middle - 1][0] < target)
            {
                return middle - 1;
            }
            right = middle - 1; // target在左区间，所以[left, middle - 1]
        }
        else if (fa[middle][0] < target)
        {
            if (fa[middle + 1][0] > target)
            {
                return middle;
            }
            left = middle + 1; // target在右区间，所以[middle + 1, right]
        }
        else
        { // 既不在左边，也不在右边，那就是找到答案了
            while (fa[middle + 1][0] == target)
            {
                middle++;
            }
            return middle;
        }
    }
    // 没有找到目标值
    return -1;
}
int main()
{
    int a, b;
    int n, q, L;
    cin >> n >> q >> L;
    vector<vector<int>> fa(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        fa[i].push_back(a);
        fa[i].push_back(b);
        fa[i].push_back(i);
    }
    sort(fa.begin(), fa.end(), cmp_l);
    for (int i = 0; i < q; i++)
    {
        int flag = 0;
        int size = 0;
        cin >> a >> b;
        int lower = search_min(fa, n, a);
        for (int j = lower; j >= 0; j--)
        {
            if (fa[j][1] >= b)
            {
                int temp = fa[j][1] - fa[j][0];
                if (flag == 0)
                {
                    flag = temp;
                    size = fa[j][2] + 1;
                }
                else
                {
                    if (flag > temp)
                    {
                        flag = temp;
                        size = fa[j][2] + 1;
                    }
                }
            }
        }
        if (flag != 0)
        {
            cout << size << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}