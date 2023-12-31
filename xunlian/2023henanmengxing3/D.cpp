// #include <bits/stdc++.h>
// using namespace std;
// vector<int> vec;

// void solve()
// {
//     int a, s, temp;
//     cin >> a >> s;
//     temp = a;
//     if (a << 1 > s)
//     {
//         cout << "No" << endl;
//         return;
//     }
//     int n = __lg(a) + 1;
//     for (int i = 1; i <= n; i++)
//     {
//         if (temp % 2)
//         {
//             vec.push_back(i);
//         }
//         temp = temp >> 1;
//     }
//     s -= a << 1;
//     n = vec.size();
//     for (int i = 0; i < n; i++)
//     {
//         if ((s >> vec[i] - 1) % 2)
//         {
//             cout << "No" << endl;
//             return;
//         }
//     }
//     // if(s & a)
//     // {
//     //     cout << "No" << endl;
//     //     return;
//     // }
//     cout << "Yes" << endl;
// }
// int main()
// {

//     freopen("E:\\Code\\Vision Studio Code\\C++\\iostream\\input.text", "r", stdin);   // 输入重定向，输入数据将从D盘根目录下的in.txt文件中读取
//     freopen("E:\\Code\\Vision Studio Code\\C++\\iostream\\output.text", "w", stdout); // 输出重定向，输出数据将保存在D盘根目录下的out.txt文件中
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
// }


#include <bits/stdc++.h>
using namespace std;
vector<int> vec;

void solve()
{
    int a, s, temp;
    cin >> a >> s;
    temp = a;
    int n = __lg(a) + 1;
    for (int i = 1; i <= n; i++)
    {
        if (temp % 2)
        {
            vec.push_back(i);
        }
        temp = temp >> 1;
    }
    for(int i : vec)
    {
        cout << i;
    }
    n = vec.size();
    for (int i = 0; i < n; i++)
    {
        if ((s >> (vec[i] - 1)) % 2)
        {
            cout << "No" << endl;
            return;
        }
    }
    // cout << "Yes" << endl;
}
int main()
{

    freopen("E:\\Code\\Vision Studio Code\\C++\\iostream\\input.text", "r", stdin);   // 输入重定向，输入数据将从D盘根目录下的in.txt文件中读取
    freopen("E:\\Code\\Vision Studio Code\\C++\\iostream\\output.text", "w", stdout); // 输出重定向，输出数据将保存在D盘根目录下的out.txt文件中
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}