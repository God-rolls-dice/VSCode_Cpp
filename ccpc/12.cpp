#include <bits/stdc++.h>
using namespace std;
int T = 0;
vector<long long> H;
long long pow_1(long long a, long long &i)
{
    long long b = 1;
    while (b - 1 <= a)
    {
        b = b * 2;
        i++;
    }
    return b / 2;
}
int main()
{
    cin >> T;
    long long temp = 0;
    for (int i = 0; i < T; i++)
    {
        cin >> temp;
        H.push_back(temp);
    }
    long long flag;
    for (int i = 0; i < T; i++)
    {
        flag = 0, temp = 0;
        temp = pow_1(H[i], flag);
        flag--;
        H[i] = H[i] - temp + 1;
        while (H[i])
        {
            int b = 1;
            if (H[i] > 1)
            {
                while (b <= H[i])
                {
                    b = b * 2;
                }
                b = b / 2;
                H[i] = H[i] - b;
                flag++;
            }
            else if (H[i] == 1)
            {
                flag++;
                H[i] = H[i] - 1;
            }
        }
        cout << flag << endl;
    }
}
