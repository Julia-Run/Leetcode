/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                dp[i] = max(max(dp[i - j] * j, dp[i]), j * (i - j));
            }
        }
        return dp[n];
    }
};
// @lc code=end
