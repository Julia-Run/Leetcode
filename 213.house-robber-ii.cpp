/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // dp -- change; rob 1th, no last; / no 1st, last
        // dp[i] = dp[i-1] || dp[i-2] + cur;  // start from 2;
        int n = nums.size();
        if (n < 2)
            return nums[0];
        else if (n == 2)
            return max(nums[0], nums[1]);
        else
            return max(help(nums, 0, n - 1), help(nums, 1, n));
    }

    int help(vector<int> &nums, int s, int e)
    {
        vector<int> dp(e + 1, 0);
        // 0--0, 1--0, s = 1, 1--n;
        // 0--0, 1--*, s = 0,--n-1;
        dp[s + 1] = nums[s];
        for (int i = s + 2; i <= e; ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[e];
    }
};
// @lc code=end
