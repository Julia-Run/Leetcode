/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        if (n < 2)
            return 0;
        int sum = 0;
        vector<int> buy(n + 1, INT_MIN);
        vector<int> sell(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i - 1]);
            sell[i] = max(sell[i - 1], buy[i] + prices[i-1] - fee);
        }
        return sell[n];
    }
};
// @lc code=end
