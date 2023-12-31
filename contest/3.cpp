#include <bits/stdc++.h>
using namespace std;
int N = 0, k = 0;
int main()
{
    int search_1(int left, int right, vector<int> a, int min, int max);
    int n = 0;
    cin >> N;
    vector<int> num_1, f[N + 2];
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        int flag_1 = 0, flag_2 = 0;
        int temp_1 = 0, temp_2 = 0;
        while (n--)
        {
            cin >> temp_1 >> temp_2;
            if (flag_1 == 0)
            {
                num_1.push_back(temp_1);
                num_1.push_back(temp_2);
                f[k].push_back(1);
                flag_1++;
            }
            else
            {
                int i = search_1(0, num_1.size() - 1, num_1, temp_1, temp_2);
                if (i != -1)
                {
                    num_1.insert(num_1.begin() + i, temp_1);
                    num_1.insert(num_1.begin() + i + 1, temp_1);
                    if (!flag_2)
                    {
                        f[k].push_back(2);
                        flag_2++;
                    }
                    else
                    {
                        f[k].push_back(1);
                    }
                }
                else
                {
                    f[k].clear();
                    f[k].push_back(-1);
                    break;
                }
            }
        }
        num_1.clear();
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        for (auto j : f[i])
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

int search_1(int left, int right, vector<int> a, int min, int max)
{
    if (left == right)
    {
        return -1;
    }
    else
    {
        int mid = left + (left + right) / 2;
        if (a[mid] < min && max < a[mid + 1])
        {
            return mid + 1; // 中间没有数，就成功
        }
        else if (min > a[mid + 1])
        {
            if (mid + 2 == (int)a.size())
            {
                return a.size();
            }
            else
            {
                search_1(mid + 1, right, a, min, max);
            }
        }
        else if (max < a[min])
        {
            if (min == 0)
            {
                return 0;
            }
            else
            {
                search_1(left, min, a, min, max);
            }
        }
        else
        {
            return -1;
        }
    }
    return -1;
}
