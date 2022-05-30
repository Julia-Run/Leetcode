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
        int res = 0;
        if (n <= 2 * k)
        {
            for (int i = 1; i < n; ++i)
                res += max(0, prices[i] - prices[i - 1]);
            return res;
        }

        // k < n;
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            int cur = prices[i];
            for (int j = 1; j <= k; ++j)
            {
                buy[j] = max(buy[j], sell[j - 1] - cur);
                sell[j] = max(sell[j], buy[j] + cur);
            }
        }
        return sell[k];
    }
};
// @lc code=end
