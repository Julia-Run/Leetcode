/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // dp, bag, coints -- dp[amount]
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int cur = coins[i - 1];
            for (int j = cur; j <= amount; ++j)
                dp[j] = min(dp[j - cur] + 1, dp[j]);
        }
        return dp[amount] < amount + 1 ? dp[amount] : -1;
    }
};
// @lc code=end
