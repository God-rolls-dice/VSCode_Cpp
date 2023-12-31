#include <bits/stdc++.h>
using namespace std;
string Top, Left;
vector<vector<string>> res(3);
vector<string> vec;
int N;
bool flag;

void dp(int r, long long fg)
{
    if (flag)
    {
        return;
    }
    if (r == N)
    {
        flag = true;
        cout << "Yes\n";
        for (auto nx: vec)
        {
            cout << nx << endl;
        }
        return;
    }
    for (auto nx: res[Left[r] - 'A'])
    {
        vec.push_back(nx);
        long long tp_fg = fg;
        bool tp_flag = true;
        for (int i = 0; i < N; i++)
        {
            if (nx[i] == '.')
            {
                continue;
            }
            int tp = nx[i] - 'A';
            if ((fg & (1 << (4 * i + tp))) == 0)
            {
                tp_flag = false;
                break;
            }
            tp_fg ^= (1 << (4 * i + tp));
            if ((fg & (1 << (4 * i + 3))) != 0)
            {
                if (nx[i] != Top[i])
                {
                    tp_flag = false;
                    break;
                }
                tp_fg = tp_fg ^ (1 << (4 * i + 3));
            }
        }
        if (tp_flag)
        {
            dp(r + 1, tp_fg);
        }
        vec.pop_back();
    }

    

}
int main()
{
    cin >> N >> Left >> Top;
    string tp = "ABC";
    for (int i = 3; i < N; i++)
    {
        tp.insert(0, ".");
    }
    sort(tp.begin(), tp.end());
    do
    {
        for (auto nx: tp)
        {
            if (nx != '.')
            {
                res[nx - 'A'].push_back(tp);
                break;
            }
            
        }
 
    }while (next_permutation(tp.begin(), tp.end()));
    dp(0, (1 << (4 * N)) - 1);
    if (!flag)
    {
        cout << "No";
    }
}