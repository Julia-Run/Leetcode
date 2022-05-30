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
        int n = prices.size();
        int res = 0, buy = INT_MIN, sell = 0;
        for (int i = 0; i < n; ++i)
        {
            buy = max(buy, -prices[i]);
            sell = buy + prices[i];
            res = max(res, sell);
        }
        return res;
    }
};
// @lc code=end
