// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 20010;

// int dp[N], pre[N], q[N];
// int n, m;

// int main()
// {
//     cin >> n >> m;
//     for (int i = 0; i < n; ++i)
//     {
//         memcpy(pre, dp, sizeof(dp));
//         int v, w, s;
//         cin >> v >> w >> s;
//         for (int j = 0; j < v; ++j)
//         {
//             int head = 0, tail = -1;    //head为队列头值，tail为队列尾值
//             for (int k = j; k <= m; k += v)
//             {
//                 if (head <= tail && k - s * v > q[head])
//                     ++head;     //保证q里面装的范围为 s*v 这个范围内

//                 while (head <= tail && pre[q[tail]] - (q[tail] - j) / v * w <= pre[k] - (k - j) / v * w)
//                     --tail;     //保证头部是最大值

//                 if (head <= tail)
//                     dp[k] = max(dp[k], pre[q[head]] + (k - q[head]) / v * w);

//                 q[++tail] = k;      //q里面存的是由小到大物品能到达的体积值
//             }
//         }
//     }
//     cout << dp[m] << endl;      //dp里面存放的是最大价值
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int N, V, s, v, w;
int main()
{
    cin >> N >> V;
    int dp[V + 1] = {0}, pre[V + 1] = {0}, q[V + 1] = {0};
    for (int i = 1; i <= N; i++)
    {
        memcpy(pre, dp, sizeof(dp));        //在每一组数组过后才
        cin >> v >> w >> s;
        for (int j = 0; j < v; j++)
        {
            int head = 0, tail = -1;

            for (int k = j; k <= V; k += v)
            {
                if (head <= tail && k - s * v > q[head])
                {
                    head++;
                }
                while (head <= tail && pre[q[tail]] - (q[tail] - j) / v * w <= pre[q[k]] - (k - j) / v * w)
                {
                    tail--;
                }
                q[++tail] = k;
                dp[k] = max(pre[k], pre[q[head]] + (k - q[head]) / v * w);
            }
        }
    }
    cout << dp[V];
}