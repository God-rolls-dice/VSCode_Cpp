#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    long long num = 0;
    int a[4] = {0}, flag = 0;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (flag == 0)
        {
            if (s[i] == '[')
            {
                a[0] = i;
                flag++;
            }
        }
        else if (flag == 1)
        {
            if (s[i] == ':')
            {
                a[1] = i;
                flag++;
                break;
            }
        }
    }
    if (flag != 2)
    {
        cout << -1;
        return 0;
    }
    for (int i = len - 1; i > a[1]; i--)
    {
        if (flag == 2)
        {
            if (s[i] == ']')
            {
                a[2] = i;
                flag++;
            }
        }
        else if (flag == 3)
        {
            if (s[i] == ':')
            {
                a[3] = i;
                flag++;
            }
        }
        else if (flag == 4)
        {
            if (s[i] == '|')
            {
                num++;
            }
        }
    }
    if (flag != 4)
    {
        cout << -1;
        return 0;
    }
    else
    {
        cout << num + 4;
    }
}