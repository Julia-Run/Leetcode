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
        int buy = INT_MAX, dp = 0;
        for (int i = 0; i < n; ++i)
        {
            buy = min(buy, prices[i]);
            dp = max(dp, prices[i] - buy); 
        }
        return dp;
    }
};
// @lc code=end
