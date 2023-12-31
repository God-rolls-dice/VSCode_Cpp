#include <bits/stdc++.h>
using namespace std;
int gcd(int m, int n) //(m>n)
{
    return n ? gcd(n, m % n) : m;
}
int notor(int a, int b)
{
    return a ^ b;
}
int main()
{
    int flag = 0;
    int l1 = 0, r1 = 0, l2 = 0, r2 = 0, long1, long2;
    cin >> l1 >> r1 >> l2 >> r2;
    long1 = r1 - l1 + 1;
    long2 = r2 - l2 + 1;
    int m = 0, n = 0;
    for (int i = 0; i < long1; i++)
    {
        for (int j = 0; j < long2; j++)
        {
            if (l1 + i > l2 + j)
            {
                m = l1 + i;
                n = l2 + j;
            }
            else
            {
                m = l2 + j;
                n = l1 + i;
            }
            if (notor(m, n) < gcd(m, n))
            {
                flag++;
            }
        }
    }
    cout << flag;
}