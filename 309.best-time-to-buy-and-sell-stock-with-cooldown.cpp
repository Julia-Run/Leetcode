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
        if (n < 2)
            return 0;
        // state: buy, sell, cooldown;
        //  buy have to be after cooldown;
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        dp[0][0] = INT_MIN;
        for (int i = 1; i <= n; ++i)
        {
            int j = i - 1;
            //  buy after cool, or not buy (increasing); 
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[j]);
            // sell for cirtainty; if increasing, sell increase; if decreasing, 
            dp[i][1] = dp[i][0] + prices[j];
            // cool after i-1 sell or cool after i-1 calm; 
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }
        return max(dp[n][1], dp[n][2]);
    }
};
// @lc code=end
