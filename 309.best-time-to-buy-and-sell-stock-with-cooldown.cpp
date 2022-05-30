/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        dp[0][0] = INT_MIN;
        for (int i = 1; i <= n; ++i)
        {
            int cur = prices[i - 1];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - cur);
            dp[i][1] = dp[i][0] + cur;
            dp[i][2] = max(dp[i - 1][1], dp[i-1][2]);
        }
        return max(dp[n][1], dp[n][2]);
    }
};
// @lc code=end
