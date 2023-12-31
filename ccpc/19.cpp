#include <bits/stdc++.h>
using namespace std;
bool pd(int begin, string a)
{
    int end = a.length() - 1;
    while (begin <= end)
    {
        if (a[begin] == a[end])
        {
            begin++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int T;
    cin >> T;
    string temp;
    for (int i = 0; i < T; i++)
    {
        vector<vector<int>> word(26, vector<int>(1, 0));
        cin >> temp;
        if (temp.size() == 1)
        {
            cout << "NaN" << endl;
            continue;
        }
        int len = temp.length();
        char flag = temp[len - 1];
        word[temp[0] - 'a'][0]++;
        for (int j = 1; j < len; j++)
        {
            if (temp[j] == flag)
            {
                if (pd(j, temp))
                {
                    cout << "HE" << endl;
                    break;
                }
                else if (++word[temp[j] - 'a'][0] > 1)
                {
                    cout << "NaN" << endl;
                    break;
                }
            }
            else if (++word[temp[j] - 'a'][0] > 1)
            {
                cout << "NaN" << endl;
                break;
            }
        }
    }
}