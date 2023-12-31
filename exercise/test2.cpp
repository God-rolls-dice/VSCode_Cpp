#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, k, i = 0;
    cin >> n >> k;
    int na[k] = {0};
    int copy[k] = {0};
    int num[n] ={0};
    for (i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (int j = n - 1; j > i; j--)
        {
            if (num[j] > num[j - 1])
            {
                swap(num[j], num[j - 1]);
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }

    for (i = 0; i < k; i++)
    {
        copy[i] = num[i];
        while (num[i] != 0)
        {
            na[i] = na[i] + num[i] % 10;
            num[i] = num[i] / 10;
        }
    }
    for (i = 0; i < k - 1; i++)
    {

        for (int j = k - 1; j > i; j--)
        {
            if (na[j] < na[j - 1])
            {
                swap(na[j], na[j - 1]);
                swap(copy[j], copy[j - 1]);
                }
        }
    }
    for (i = 0; i < k; i++)
    {
        cout << copy[i] << " ";
    }
}
