#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> a, b;
    long long temp = 0;
    for (int i = 0; i < n; i++)
    {
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] + 1 == a[i + 1])
        {
            if (flag == 0)
                b.push_back(a[i]);
            b.push_back(a[i + 1]);
        }
    }
    if(a>0)
}