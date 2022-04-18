/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 3)
            return n;
        vector<int> res(n + 1, 1);
        for (int i = 2; i < n + 1; ++i)
        {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n];
    }
};
// @lc code=end
