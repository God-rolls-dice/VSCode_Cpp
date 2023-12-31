#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x = 0, n = 0, y = 0;
    cin >> x >> n >> y;
    long long i = 0;
    if (!x % n)
    {
        i = x / n;
    }
    else
    {
        i = x / n + 1;
    }
    long long temp = i * n;
    while (temp <= y && i <= 100000)
    {
        if (temp - x >= 0)
        {
            cout << temp - x << " ";
        }
        i++;
        temp = i * n;
    }
}