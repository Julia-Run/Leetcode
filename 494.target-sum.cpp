/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum)
            return 0;
        if ((sum - target) % 2)
            return 0;
        int t = (sum - target) / 2;
        vector<int> dp(t + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            int v = nums[i];
            for (int j = t; j - v >= 0; --j)
            {
                dp[j] = dp[j] + dp[j - v];
            }
        }
        return dp[t];
    }
};
// @lc code=end
