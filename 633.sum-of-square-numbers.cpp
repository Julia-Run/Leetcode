/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long lo = 0, hi = sqrt(c);
        long sum;
        while (lo <= int(sqrt(c)) && hi >= 0)
        {
            sum = lo * lo + hi * hi;
            if (sum == c)
                return true;
            else if (sum > c)
                --hi;
            else
                ++lo;
        }
        return false;
    }
};
// @lc code=end
