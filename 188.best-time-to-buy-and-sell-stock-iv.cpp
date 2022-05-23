/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;
        if (2 * k >= n)
        { // max profit in unlimited transactions;
            int sum = 0;
            for (int i = 1; i < n; ++i)
                sum += max(0, prices[i] - prices[i - 1]);
            return sum;
        }

        // dp
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};
// @lc code=end
