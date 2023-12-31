#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int N, K, Q, p, v, ans = 0;
    cin >> N >> K >> Q;
    vector<int> B(N + 1, 0), A(N + 1, 0);
    for (int i = 1; i <= Q; i++)
    {
        cin >> p >> v;
        if (A[p])
        {
            auto tp1 = upper_bound(B.begin() + 1, B.end(), A[p], greater<int>());
            if (tp1 - 1 <= B.begin() + K)
            {
                ans += B[K + 1] - A[p];
            }
            B.erase(tp1 - 1);
        }
        auto tp = upper_bound(B.begin() + 1, B.end(), v, greater<int>());
        if (tp <= B.begin() + K)
        {
            ans += v - B[K];
        }
        if (tp != B.end())
        {
            B.insert(tp, v);
        }

        A[p] = v;
        cout << ans << endl;
    }
}
// #include <bits/stdc++.h>

// using namespace std;

// int k;
// multiset<int> x, y;
// long long s;

// void balance()
// {
//     while (x.size() < k)
//     {
//         auto iy = y.end();
//         iy--;
//         x.insert((*iy));
//         s += (*iy);
//         y.erase(iy);
//     }
//     if (x.empty() || y.empty())
//     {
//         return;
//     }

//     while (1)
//     {
//         auto ix = x.begin();
//         auto iy = y.end();
//         iy--;
//         int ex = (*ix);
//         int ey = (*iy);
//         if (ex >= ey)
//         {
//             break;
//         }
//         s += (ey - ex);
//         x.erase(ix);
//         y.erase(iy);
//         x.insert(ey);
//         y.insert(ex);
//     }
// }

// void add(int v)
// {
//     y.insert(v);
//     balance();
// }

// void erase(int v)
// {
//     auto ix = x.find(v);
//     if (ix != x.end())
//     {
//         s -= v;
//         x.erase(ix);
//     }
//     else
//     {
//         y.erase(y.find(v));
//     }
//     balance();
// }

// int main()
// {
//     int n;
//     cin >> n >> k;
//     vector<int> a(n, 0);
//     for (int i = 0; i < k; i++)
//     {
//         x.insert(0);
//     }
//     for (int i = k; i < n; i++)
//     {
//         y.insert(0);
//     }
//     s = 0;

//     int q;
//     cin >> q;
//     while (q > 0)
//     {
//         q--;
//         int p, w;
//         cin >> p >> w;
//         p--;
//         add(w);
//         erase(a[p]);
//         a[p] = w;
//         cout << s << "\n";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// int k;
// multiset<int> x, y;
// long long s;

// void balance()
// {
//     while (x.size() < k)
//     {
//         auto iy = y.end();
//         iy--;
//         x.insert((*iy));
//         s += (*iy);
//         y.erase(iy);
//     }
//     if (x.empty() || y.empty())
//     {
//         return;
//     }

//     while (1)
//     {
//         auto ix = x.begin();
//         auto iy = y.end();
//         iy--;
//         int ex = (*ix);
//         int ey = (*iy);
//         if (ex >= ey)
//         {
//             break;
//         }
//         s += (ey - ex);
//         x.erase(ix);
//         y.erase(iy);
//         x.insert(ey);
//         y.insert(ex);
//     }
// }

// void add(int v)
// {
//     y.insert(v);
//     balance();
// }

// void erase(int v)
// {
//     auto ix = x.find(v);
//     if (ix != x.end())
//     {
//         s -= v;
//         x.erase(ix);
//     }
//     else
//     {
//         y.erase(y.find(v));
//     }
//     balance();
// }

// int main()
// {
//     int n;
//     cin >> n >> k;
//     vector<int> a(n, 0);
//     for (int i = 0; i < k; i++)
//     {
//         x.insert(0);
//     }
//     for (int i = k; i < n; i++)
//     {
//         y.insert(0);
//     }
//     s = 0;

//     int q;
//     cin >> q;
//     while (q > 0)
//     {
//         q--;
//         int p, w;
//         cin >> p >> w;
//         p--;
//         add(w);
//         erase(a[p]);
//         a[p] = w;
//         cout << s << "\n";
//     }
//     return 0;
// }
