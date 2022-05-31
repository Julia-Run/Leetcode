/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // adjacent is not allowed; find max val;
        // nums.size()--[1,100]; boundary;
        // why dp? dp[i-1] or dp[i-2]+cur;
        // and dp[i+1] >= dp[i];
        // 1-1,2-1 or 0+2,
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        return dp[n];
    }
};
// @lc code=end
