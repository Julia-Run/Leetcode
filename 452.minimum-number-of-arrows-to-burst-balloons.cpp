/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        // size: points>=1;
        // intervals, how many unoverlaped.
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        // if pre_end < curr_start, un-overlapped, ++arrow;
        int arrow = 1;
        int pre = points[0][1];
        for (int i = 1; i < points.size(); ++i)
        {
            if (pre < points[i][0])
            {
                ++arrow;
                pre = points[i][1];
            }
        }
        return arrow;
    }
};
// @lc code=end
