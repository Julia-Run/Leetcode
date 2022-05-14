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
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); ++i)
        {
            int v = coins[i];
            for (int j = v; j <= amount; ++j)
            {
                dp[j] = min(dp[j], 1 + dp[j - v]);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
// @lc code=end
