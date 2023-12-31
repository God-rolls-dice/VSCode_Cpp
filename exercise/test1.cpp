class Solution
{
public:
    bool isMatch(string s, string p)
    {
        auto allStars = [](const string &str, int left, int right)      //查找字母和'?'
        {
            for (int i = left; i < right; ++i)
            {
                if (str[i] != '*')
                {
                    return false;
                }
            }
            return true;
        };
        auto charMatch = [](char u, char v)         //匹配这两字符是否相匹配
        {
            return u == v || v == '?';
        };

        while (s.size() && p.size() && p.back() != '*')         //使末尾为*，不匹配返回F
        {
            if (charMatch(s.back(), p.back()))
            {
                s.pop_back();
                p.pop_back();
            }
            else
            {
                return false;
            }
        }
        if (p.empty())
        {
            return s.empty();
        }

        int sIndex = 0, pIndex = 0;
        int sRecord = -1, pRecord = -1;
        while (sIndex < s.size() && pIndex < p.size())
        {
            if (p[pIndex] == '*')
            {
                ++pIndex;
                sRecord = sIndex;
                pRecord = pIndex;
            }
            else if (charMatch(s[sIndex], p[pIndex]))
            {
                ++sIndex;
                ++pIndex;
            }
            else if (sRecord != -1 && sRecord + 1 < s.size())
            {
                ++sRecord;
                sIndex = sRecord;
                pIndex = pRecord;
            }
            else
            {
                return false;
            }
        }
        return allStars(p, pIndex, p.size());
    }
};
 