/* #include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int, int> myhash;
    vector<int> a, b;
    int flag;
    while (cin.peek() != '\n')
    {
        cin >> flag;
        a.push_back(flag);
    }
    b.push_back(a[0]);
    int n = a.size();
    int len = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= b[len])
        {
            b.push_back(a[i]);
            len++;
        }
        else
        {
            vector<int>::iterator num = upper_bound(b.begin(), b.end(), a[i], greater<int>());
            *num = a[i];
            myhash[num - b.begin()]++;
        }
    }
    int max = 0;
    for (auto i : myhash)
    {
        if (i.second > max)
            max = i.second;
    }
    cout << b.size() << endl;
    cout << max + 1;
}
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a, b, c;
    int flag;
    while (cin.peek() != '\n')
    {
        cin >> flag;
        a.push_back(flag);
    }
    b.push_back(a[0]);
    c.push_back(a[0]);
    int n = a.size();
    int len_b = 0, len_c = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= b[len_b])
        {
            b.push_back(a[i]);
            len_b++;
        }
        else
        {
            vector<int>::iterator num = upper_bound(b.begin(), b.end(), a[i], greater<int>());
            *num = a[i];
        }
        if (a[i] > c[len_c])
        {
            c.push_back(a[i]);
            len_c++;
        }
        else
        {
            vector<int>::iterator num = lower_bound(c.begin(), c.end(), a[i]);
            *num = a[i];
        }
    }
    cout << b.size() << endl;
    cout << c.size();
}
