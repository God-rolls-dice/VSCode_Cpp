#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> row(3);
bool fnd = false;
int n;
string r, c;
vector<string> grid;

void dfs(int i, int fl)
{
    if (fnd)
    {
        return;
    }
    if (i == n)
    {
        if (fl == 0)
        {
            cout << "Yes\n";
            for (auto &nx : grid)
            {
                cout << nx << "\n";
            }
            fnd = true;
        }
        return;
    }
    for (auto &nx : row[r[i] - 'A'])    //以r[i] - 'A'开头的字符串保证了最前面的是r
    {
        grid.push_back(nx);

        int ufl = fl;
        bool und = true;
        for (int j = 0; j < n; j++)
        {
            if (nx[j] == '.')       //选第一个不为'.'的字符
            {
                continue;
            }
            int kind = (nx[j] - 'A');   
            if ((fl & (1 << (4 * j + kind))) == 0)      //如果为零表示第j位的 kind + 'A'字符已经被使用过了，退出
            {
                und = false;
                break;
            }
            ufl ^= (1 << (4 * j + kind));       //标记第j个字符的第kind + 'A'的字符，同一列不能再使用相同的字符。
            if ((fl & (1 << (4 * j + 3))) != 0)     //如果第j位之前没有被选择过
            {
                if (nx[j] != c[j])      //与最上面那串字符同一列的第一个不为'.'的字符一定要等于c
                {
                    und = false;
                    break;
                }
                ufl ^= (1 << (4 * j + 3));      //打上标记表示第j位已经被选取过
            }
        }

        if (und)
        {
            dfs(i + 1, ufl);    //第i行满足条件判断第i + 1行
        }
        grid.pop_back();
    }
}

int main()
{
    cin >> n >> r >> c;
    string abc = "ABC";
    while (abc.size() < n)
    {
        abc.push_back('.');
    }
    sort(abc.begin(), abc.end());
    do
    {
        char tg = '.';
        for (auto &nx : abc)
        {
            if (nx != '.')
            {
                tg = nx;
                break;
            }
        } 
        row[tg - 'A'].push_back(abc);   //row[i]里面装的是以 i + 'A' 字母开头的字符串
    } while (next_permutation(abc.begin(), abc.end()));

    dfs(0, (1 << (4 * n)) - 1);
    if (!fnd)
    {
        cout << "No\n";
    }
    return 0;
}
