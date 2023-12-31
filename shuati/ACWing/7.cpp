#include <bits/stdc++.h>
using namespace std;
int N, V, v, w, s;
int main()
{
    cin >> N >> V;
    int f[V + 1] = {0}, q[V + 1] = {0};
    for (int i = 1; i <= N; i++)
    {
        cin >> v >> w >> s;
        if (s == -1)
        {
            for (int j = V; j >= v; j--)
            {
                f[j] = max(f[j], f[j - v] + w);
            }
        }
        else if (s == 0)
        {
            for (int j = v; j <= V; j++)
            {
                f[j] = max(f[j], f[j - v] + w);
            }
        }
        else
        {
            for (int j = 0; j < v; j++)
            {
                int head = 0, tail = -1;
                for (int k = j; k < V; k += v)
                {
                    if (head <= tail && k - s * v > q[head])
                    {
                        head++;
                    }
                    if (head <= tail && f[q[tail]] - (q[tail] - j) / v * w < f[k] - (k - j) / v * w)
                    {
                        tail++;
                    }
                    q[++tail] = k;
                    f[k] = max(f[k], f[q[head]] + (k - q[head]) / v * w);
                }
            }
        }
    }
    cout << f[V];
}
