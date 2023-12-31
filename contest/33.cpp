// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int a, b;
//     vector<int> weight;
//     vector<int> size1;
//     vector<int> size2;
//     int zore = 0;
//     for (int i = 0; i < a; i++)
//     {
//         int num;
//         cin >> num;
//         if (num > 0)
//         {
//             size1.push_back(num);
//         }
//         else if (num < 0)
//         {
//             size2.push_back(num);
//         }
//         else
//         {
//             zore = 1;
//         }
//     }
//     for (int i = 0; i < b; i++)
//     {
//         int num;
//         cin >> num;
//         weight.push_back(num);
//     }
//     sort(weight.begin(), weight.end());
//     sort(size1.begin(), size1.end());
//     sort(size2.begin(), size2.end());
//     vector<int> newweight;
//     int n = weight[0];
//     if (n != 1)
//     {
//         int flag = 0;
//         int temp = 0;
//         for (int i = 0; i < b; i++)
//         {
//             temp = weight[i] % n;
//             if (!temp)
//             {
//                 newweight.push_back(weight[i] / n);
//             }
//             else
//             {
//                 newweight = weight;
//                 break;
//             }
//         }
//     }

// }

// Memory Time
// 1496K  0MS

// 我所使用的解题方法，由于dp状态方程组申请空间比较大大
//     若dp为局部数组，则会部分机器执行程序时可能由于内存不足会无法响应
//         所以推荐定义dp为全局数组，优先分配内存

#include <bits/stdc++.h>
using namespace std;

int dp[21][15001]; // 状态数组dp[i][j]
                   // 放入（挂上）前i个物品（钩码）后，达到j状态的方法数
int main(int i, int j, int k)
{
    int n;     // 挂钩数
    int g;     // 钩码数
    int c[21]; // 挂钩位置
    int w[21]; // 钩码重量

    /*Input*/

    cin >> n >> g;

    for (i = 1; i <= n; i++)
        cin >> c[i];
    for (i = 1; i <= g; i++)
        cin >> w[i];

    /*Initial*/

    memset(dp, 0, sizeof(dp)); // 达到每个状态的方法数初始化为0
    dp[0][7500] = 1;           // 7500为天枰达到平衡状态时的平衡度
                               // 放入前0个物品后，天枰达到平衡状态7500的方法有1个，就是不挂钩码

    /*DP*/

    for (i = 1; i <= g; i++)
        for (j = 0; j <= 15000; j++)
            if (dp[i - 1][j]) // 优化，当放入i-1个物品时状态j已经出现且被统计过方法数，则直接使用统计结果
                              // 否则忽略当前状态j，而且i是不会增加的，当出现dp[i-1][j]时所处也在范围内
                for (k = 1; k <= n; k++)
                    dp[i][j + w[i] * c[k]] += dp[i - 1][j]; // 状态方程

    /*Output*/

    cout << dp[g][7500] << endl;
    return 0;
} // 最佳

// #include <iostream>
// #include <stdio.h>
// using namespace std;
// int dp[22][15000], a[22], b[22];
// int main()
// {
//     int an, bn;
//     cin >> an >> bn;
//     for (int i = 1; i <= an; i++)
//         scanf("%d", &a[i]);
//     for (int i = 1; i <= bn; i++)
//         scanf("%d", &b[i]);
//     dp[0][7500] = 1;
//     for (int i = 1; i <= bn; i++)
//     {
//         for (int j = 0; j <= 15000; j++)
//         {
//             for (int k = 1; k <= an; k++)
//             {
//                 if (j >= a[k] * b[i])
//                     dp[i][j] += dp[i - 1][j - a[k] * b[i]];
//             }
//         }
//     }
//     cout << dp[bn][7500];
//     return 0;
// }
