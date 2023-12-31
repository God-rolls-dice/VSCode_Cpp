/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int Sum = 0;
        int n = height.size();
        int i, Max_height = 0, Max_n = 0, len1 = 0, len2 = 0;
        for (i = 0; i < n; i++) //找到最大值
        {
            if (Max_height < height[i])
            {
                Max_height = height[i];
                Max_n = i;
            }
        }
        int height_left = height[0];
        int height_right = height[n - 1];
        int height_Nl = 0;
        int height_Nr = n - 1;
        for (i = 1; i <= Max_n; i++)
        {
            if (height[i] >= height_left)
            {
                Sum += height_left * (i - height_Nl - 1);
                height_Nl = i;
                height_left = height[i];
            }
            else
                Sum -= height[i];
        }
        for (i = n - 2; i >= Max_n; i--)
        {
            if (height[i] >= height_right)
            {
                Sum += height_right * (height_Nr - i - 1);
                height_Nr = i;
                height_right = height[i];
            }
            else
                Sum -= height[i];
        }
        return Sum;
    }
}

;
// @lc code=end
