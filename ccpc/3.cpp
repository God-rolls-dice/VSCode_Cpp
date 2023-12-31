#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    getline(cin, a);
    long long i = a.length();
    for (long long j = 0; j < i, j++)
    {
        if (a[j] == '<')
            cout << "&lt;";
        else if (a[j] == '>')
        {
            cout << "&gt;";
        }
        else
        {
            cout << a[j];
        }
    }
}