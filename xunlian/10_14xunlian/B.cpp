#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    char a[4];
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int i = 0; i < 4; i++)
        {
            a[i] = s[i];
        }
        sort(a, a + 4);
        if (a[0] == a[1] && a[0] == a[2] && a[0] != a[3])
        {
            cout << "Yes";
            if (i + 1 < n)
            {
                cout << endl;
            }
        }
        else if (a[1] == a[2] && a[1] == a[3] && a[1] != a[0])
        {
            cout << "Yes"; 
            if (i + 1 < n)
            {
                cout << endl;
            }
        }
        else
        {
            cout << "NO";
            if (i + 1 < n)
            {
                cout << endl;
            }
        }
    }

    return 0;
}