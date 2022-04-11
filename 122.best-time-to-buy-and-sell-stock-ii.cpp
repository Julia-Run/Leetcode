/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // size: p >= 1, maxprofit, greedy
        // maxprofit: every current day;
        // int sum = 0;
        // int pre = prices[0];
        // for (int i = 1; i < prices.size(); ++i)
        // {
        //     if (prices[i] > pre)
        //     {
        //         sum += (prices[i] - pre);
        //         pre = prices[i];
        //     }
        //     else
        //         pre = prices[i];
        // }
        // return sum;

        int sum = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            sum += max(0, prices[i] - prices[i - 1]);
        }
        return sum;
    }
};
// @lc code=end
