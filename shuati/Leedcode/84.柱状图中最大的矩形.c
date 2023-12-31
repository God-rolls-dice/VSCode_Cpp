/*
 * @lc app=leetcode.cn id=84 lang=c
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
int largestRectangleArea(int *heights, int heightsSize)
{
    int i = 0, area = 0, area_max = 0, j = 0;
    int *score_r = (int *)malloc(heightsSize * sizeof(int));
    int *score_l = (int *)malloc(heightsSize * sizeof(int));
    for (i = 0; i < heightsSize; i++)
    {
        score_r[i] = 0;
        score_l[i] = 0;
    }
    for (i = heightsSize - 2; i >= 0; i--)
    {
        if (heights[i] <= heights[i + 1])
            score_l[i] = score_l[i + 1] + 1;
    }
    for (j = 0; j < heightsSize; j++)
    {
        if (j > 0 && heights[j] <= heights[j - 1])
            score_r[j] = +score_r[j - 1];
        area = (score_l[j] + score_r[j] + 1) * heights[j];
        if (area > area_max)
            area_max = area;
    }
    return area_max;
    free(score_r);
    free(score_l);
}

// @lc code=end
