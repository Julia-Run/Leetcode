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
        if (2 * k >= n)
        {
            // countless transations;
            int res = 0;
            for (int i = 1; i < n; ++i)
                res += max(0, prices[i] - prices[i - 1]); // integer for convenient;
            return res;
        }

        // max profit within k transations;
        // dp; 1d; dp[0 to k] -- max profit within k trans; how to achieve this? T to buy and T to sell?
        // buy[0 to k], sell[0 to k];
        // keep the first b/s is the max single transation as so far; not care the transation sequence;
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                //  not compare with yesterday: to decide if I buy today; 
                // max profit is olny allowed i transations; 
                buy[j] = max(buy[j], sell[j - 1] - prices[i]); // 
                sell[j] = max(sell[j], buy[j] + prices[i]); 
            }
        }
        return sell[k];
    }
};
// @lc code=end
