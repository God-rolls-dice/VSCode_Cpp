#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "aab";
    string p = "c*a*b";
    while (s.size() && p.size())
    {
        if (p.back() == s.back() || p.back() == '.')
        {
            p.pop_back();
            s.pop_back();
        }
        else if (p.back() == '*' && p[p.size() - 2] != '.')
        {
            p.pop_back();
            int num_s = 0, num_p = 0;
            char flag = p.back();
            while (p.back() == flag)
            {
                p.pop_back();
                num_p++;
            }
            while (s.back() == flag)
            {
                s.pop_back();
                num_s++;
            }
            if (num_p - 1 > num_s)
            {
                return false;
            }
        }
        else if (p.back() == '*' && p[p.size() - 2] == '.')
        {
            break;
        }
        else
        {
            return false;
        }
    }
    if (p.empty())
        return s.empty();
    int sIndex = 0, pIndex = 0;
    int sRecord = -1, pRecord = -1;
    while (sIndex < (int)s.size() && pIndex < (int)p.size()) // p不为空，s也不为空
    {
        if (s[sIndex] == p[pIndex] || (p[pIndex] == '.' && p[pIndex + 1] != '*'))
        {
            sIndex++, pIndex++;
        }
        else if (p[pIndex] == '.' && p[pIndex + 1] == '*')
        {
            pIndex = pIndex + 2;
            pRecord = pIndex;
            sRecord = sIndex;
        }
        else if (p[pIndex] != s[sIndex] && pIndex + 2 < (int)p.size() && p[pIndex + 1] == '*')
        {
            pIndex = pIndex + 2;
        }
        else if (p[pIndex] == '*')
        {
            char flag = p[pIndex - 1];
            pIndex++;
            int num_s = 0, num_p = 0;
            while (p[pIndex] == flag)
            {
                pIndex++;
                num_p++;
            }
            while (s[sIndex] == flag)
            {
                sIndex++;
                num_s++;
            }
            if (num_p - 2 > num_s)
            {
                return false;
            }
        }
        else if (sRecord != -1 && sRecord + 1 < (int)s.size())
        {
            sRecord++;
            sIndex = sRecord;
            pIndex = pRecord;
        }
        else
        {
            return false; // 当srecord为s的最后字符且没匹配时
        }
    }
    for (int i = pIndex; i < (int)p.size(); i++)
    {
        cout << (int)p.size();
        if (p[i] != '.' && p[i] != '*' && p[i + 1] != '*')
        {
            return false;
        }
    }
    return true; // 1、s,p都为空 ，2、p为空s不为空
}
