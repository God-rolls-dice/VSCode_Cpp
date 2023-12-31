// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n = 0;
//     cin >> n;
//     int flag = n;
//     vector<long long> num;
//     int i = 0;
//     while (flag--)
//     {
//         cin >> i;
//         num.push_back(i);
//     }
//     sort(num.begin(), num.end());
//     int x;
//     cin >> x;
//     flag = n / 2;
//     int count = 0;
//     for (i = 0; i < n; i++)
//     {
//         if (num[i] == x)
//         {
//             count++;
//         }
//         if (i == n / 2 && count == 0)
//         {
//             cout << 0;
//             return 0;
//         }
//     }
//     if (count >= flag)
//     {
//         cout << 1;
//         return 0;
//     }
//     cout << 0;
// }

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(void)
{
    unordered_map<int, int> myhash;
    int n, x;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
        ++myhash[vec[i]];
    }
    cin >> x;
    if (myhash[x] > n / 2)
        cout << 1;
    else
        cout << 0;
    return 0;
}