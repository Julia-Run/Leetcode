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
        // min numbers of element to be removed; no overlappings;
        // [a,b1], [b1,c] : allow this
        // 01. start from min number -- sort intervals by end_i
        // key: [a,b], there is a defalt order !!!!!!
        // 02. end_i > start_(i+1), ++ removed
        // size: intervals >= 1;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int removed = 0, pre = 0;
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[pre][1] > intervals[i][0])
                ++removed;
            else
                pre = i;
        }
        return removed;
    }
};
// @lc code=end
