#include <bits/stdc++.h>
using namespace std;

char temp;

int main()
{
    vector<char> t(1, 0);
    vector<char> a(3), b(3), c(3), d(3), e(4);
    a[0] = 'o', a[1] = 'v', a[2] = 'e';
    b[0] = 'l', b[1] = 'v', b[2] = 'e';
    c[0] = 'l', c[1] = 'o', c[2] = 'e';
    d[0] = 'l', d[1] = 'o', d[2] = 'v';
    e[0] = 'l', e[1] = 'o', e[2] = 'v', e[3] = 'e';
    string s;
    getline(cin, s);
    stringstream ss(s);
    char x;
    while (ss >> x)
        t.push_back(x);
    t.push_back('0');
    for (int i = 1; i < (int)t.size() - 2; i++)
    {
        if ((a[0] == t[i] && a[1] == t[i + 1] && a[2] == t[i + 2]) || (b[0] == t[i] && b[1] == t[i + 1] && b[2] == t[i + 2]) || (c[0] == t[i] && c[1] == t[i + 1] && c[2] == t[i + 2]) || (d[0] == t[i] && d[1] == t[i + 1] && d[2] == t[i + 2]) || (e[0] == t[i] && e[1] == t[i + 1] && e[2] == t[i + 2] && e[3] == t[i + 3]))
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
