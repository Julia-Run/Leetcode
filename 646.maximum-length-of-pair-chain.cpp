/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int res = 1;
        int pre = 0;
        for (int i = 0; i < n; ++i)
        {
            if (pairs[pre][1] < pairs[i][0])
            {
                ++res;
                pre = i;
            }
        }
        return res;
    }
};
// @lc code=end
