#include <bits/stdc++.h>
using namespace std;
int step = 0;                                                        // 步数
void change_r(char *a, int first, int end, vector<vector<int>> &r_n) // 向右移
{
    for (int i = first; i < end; i++)
    {
        --*find(r_n[a[i + 1] - 'a'].begin() + 1, r_n[a[i + 1] - 'a'].end(), i + 1);
        vector<int>::iterator it = find(r_n[a[i + 1] - 'a'].begin() + 1, r_n[a[i + 1] - 'a'].end(), i);
        if (it != (r_n[a[i + 1] - 'a'].begin() + 1))
            if (i < *(it - 1))
                swap(*it, *(it - 1));
        swap(a[i], a[i + 1]);
        step++;
    }
}
void change_l(char *a, int first, int end, vector<vector<int>> &r_n) // 向左移
{
    for (int i = first; i > end; i--)
    {
        ++*find(r_n[a[i - 1] - 'a'].begin() + 1, r_n[a[i - 1] - 'a'].end(), i - 1);
        vector<int>::iterator it = find(r_n[a[i - 1] - 'a'].begin() + 1, r_n[a[i - 1] - 'a'].end(), i);
        if (it != r_n[a[i - 1] - 'a'].end() - 1)
            if (i > *(it + 1))
                swap(*it, *(it + 1));
        swap(a[i], a[i - 1]);
        step++;
    }
}
void change(char *a, int first, int end, vector<vector<int>> &r_n) // 向右移
{
    for (int i = first; i > end; i--)
    {
        --*find(r_n[a[i] - 'a'].begin() + 1, r_n[a[i] - 'a'].end(), i);
        vector<int>::iterator it = find(r_n[a[i] - 'a'].begin() + 1, r_n[a[i] - 'a'].end(), i - 1);
        if (it != r_n[a[i] - 'a'].begin() + 1)
            if (i - 1 < *(it - 1))
                swap(*it, *(it - 1));
        ++*find(r_n[a[i - 1] - 'a'].begin() + 1, r_n[a[i - 1] - 'a'].end(), i - 1);
        vector<int>::iterator it_1 = find(r_n[a[i - 1] - 'a'].begin() + 1, r_n[a[i - 1] - 'a'].end(), i);
        if (it_1 != r_n[a[i - 1] - 'a'].end() - 1)
            if (i > *(it_1 + 1))
                swap(*it_1, *(it_1 + 1));
        swap(a[i], a[i - 1]);
        step++;
    }
}
int main()
{
    int n;
    string s;
    vector<int> Swap_l, Swap_r;
    cin >> n >> s;
    int middle = n / 2 - 1;
    char left[middle + 1] = {0}, right[middle + 1] = {0}; // 左边和右边的字符
    int num[26] = {0};
    vector<vector<int>> l_n(26, vector<int>(1, 0)), r_n(26, vector<int>(1, 0)); // 统计左边和右边对应字符数
    for (int i = 0; i <= middle; i++)
    {
        left[i] = s[i];
        right[i] = s[i + middle + 1];
    }
    for (int i = 0; i < n; i++)
    {
        if (i <= middle)
        {
            l_n[s[i] - 'a'][0]++;
            l_n[s[i] - 'a'].push_back(i);
        }
        else
        {
            r_n[s[i] - 'a'][0]++;
            r_n[s[i] - 'a'].push_back(i - middle - 1);
        }
        ++num[s[i] - 'a']; // 发现每个字母的数量
    }
    for (int i = 0; i < 26; i++) // 判断要交换的位置
    {
        while (l_n[i][0] * 2 > num[i])
        {
            Swap_l.push_back(l_n[i].back());
            l_n[i].pop_back();
            l_n[i][0]--;
            r_n[i][0]++;
        }
        while (l_n[i][0] * 2 < num[i])
        {
            Swap_r.push_back(r_n[i][1]); // 记录要交换的位置
            r_n[i].erase(r_n[i].begin() + 1, r_n[i].begin() + 2);
            l_n[i][0]++;
            r_n[i][0]--;
        }
    }
    sort(Swap_l.begin(), Swap_l.end());
    sort(Swap_r.begin(), Swap_r.end(), greater<int>());
    while (Swap_l.size()) // 必要交换+
    {
        change_r(left, Swap_l.back(), middle, l_n);
        change_l(right, Swap_r.back(), 0, r_n);
        swap(left[middle], right[0]);
        l_n[left[middle] - 'a'].push_back(middle);
        r_n[right[0] - 'a'].insert(r_n[right[0] - 'a'].begin() + 1, 0);
        step++;
        Swap_l.pop_back(), Swap_r.pop_back();
    }
    for (int i = 0; i <= middle; i++) // 以right为模板匹配交换
    {
        if (left[i] != right[i])
        {
            change(left, l_n[right[i] - 'a'][1], i, l_n);
        }
    }
    cout << step;
}
