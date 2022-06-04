/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // dp, 1d, one chance to b/s;
        // buy: log min prices before;
        // sell: profit if you sell now;
        // refresh max profit;
        int n = prices.size();
        if (n < 2)
            return 0;
        int buy = INT_MAX, sell = 0, res = 0;

        for (int i = 0; i < n; ++i)
        {
            buy = min(buy, prices[i]);
            sell = prices[i] - buy;
            res = max(res, sell);
        }
        return res;
    }
};
// @lc code=end
