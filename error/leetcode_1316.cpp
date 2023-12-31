// 输入leetcodeleetcode时i=2,j=5;i=2,j=13也满足很奇怪
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int main()
{
    string text;
    vector<ull> hash(1, 0);
    set<ull> match;
    cin >> text;
    int num = text.size();
    vector<ull> p(num + 5);
    p[0] = 1;
    for (int i = 1; i <= num; i++)
    {
        hash.push_back(hash[i - 1] * 131 + (text[i - 1] - 'a' + 1));
        p[i] = p[i - 1] * 131;
    }
    for (int i = 1; i <= num / 2; i++)
    {
        for (int j = 1; j <= num - i * 2 + 1; j++)
        {
            ull x = hash[j + i - 1] - hash[j - 1] * p[i];
            ull y = hash[j + i * 2 - 1] - hash[j + i - 1] * p[i];
            if (x == y)
            {
                match.insert(x);
            }
        }
    }
    cout << match.size();
}