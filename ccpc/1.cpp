#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a, b;
int main()
{
    int temp = 0, num_a = 0, num_b = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (!(temp % 2))
        {
            a.push_back(temp);
            num_a++;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        if (temp % 2)
        {
            num_b++;
        }
    }
    sort(a.begin(), a.end());
    if (num_a <= num_b)
    {
        cout << 0;
    }
    else
    {
        int num = num_a - num_b;
        long long sum = accumulate(a.begin(), a.begin() + num, 0ll);
        cout << sum;
    }
    return 0;
}