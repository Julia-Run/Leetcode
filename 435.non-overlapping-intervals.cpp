/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // boundaries
        int n = intervals.size();
        if (n < 2)
            return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int removed = 0;
        int pre_end = intervals[0][1];
        // pre_end > i_start, ++removed
        for (int i = 1;i<n; ++i )
        {
            if (pre_end > intervals[i][0]) ++removed;
            else pre_end = intervals[i][1];
        }
        return removed;
    }
};
// @lc code=end


