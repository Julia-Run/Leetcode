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
        // c,a,b >=0
        // double ptrs; like find two elements in a sorted array.
        long a = 0, b = sqrt(c);
        long sum;
        while (a <= b)
        // as there is no rule saying that a can't equal b, so we use "<=";
        {
            sum = a * a + b * b;
            if (sum == c)
                return true;
            else if (sum > c)
                --b;
            else
                ++a;
        }
        return false;
    }
};
// @lc code=end
