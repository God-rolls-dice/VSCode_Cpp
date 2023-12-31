#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e2 + 10;
int v, w, s, N, V;
vector<int> vec;
int main()
{
    cin >> N >> V;
    int f[V + 1];
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= N; i++)
    {
        vec.clear();
        cin >> v >> w >> s;
        int tp = 1;
        while (s > tp)
        {
            vec.push_back(tp);
            s -= tp;
            tp *= 2;
        }
        vec.push_back(s);
        for (auto nx : vec)
        {
            for (int j = V; j >= nx * v; j--)
            {
                f[j] = max(f[j], f[j - nx * v] + nx * w);
            }
        }
    }
    cout << f[V];
}