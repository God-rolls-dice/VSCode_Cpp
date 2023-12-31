#include <bits/stdc++.h>
using namespace std;

const int N1 = 300010, N2 = 100010;
int A[N1] = {0}, f[N2] = {0}, a[N1] = {0};
int n;

signed main()
{
    memset(A, 0, sizeof(A));
    memset(f, 0, sizeof(f));
    memset(a, 0, sizeof(0));
    cin >> n;
    n = n * 3;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        if (++f[A[i]] == 2)
        {
            a[i] = A[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
        cout << a[i] << " ";
    }
}
