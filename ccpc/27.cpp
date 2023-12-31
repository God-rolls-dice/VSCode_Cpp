#include <bits/stdc++.h>
using namespace std;

int T;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int n;
        cin >> n;
        unordered_map<string, vector<int>> myhash;
        vector<int> points(3, n * 3);
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                string s;
                cin >> s;
                myhash[s].emplace_back(i);
            }
        }
        for (const auto &vec : myhash)
        {
            int Size = vec.second.size();
            if (Size == 2)
            {
                for (int i = 0; i < 2; ++i)
                {
                    points[vec.second[i]] -= 2;
                }
            }
            else if (Size == 3)
            {
                for (int i = 0; i < 3; ++i)
                {
                    points[vec.second[i]] -= 3;
                }
            }
        }
        for (int i = 0; i < 3; ++i)
        {
            cout << points[i] << " ";
        }
        cout << endl;
    }

    return 0;
}