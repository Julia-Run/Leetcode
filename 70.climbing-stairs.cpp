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
        // 1--1, 2--2, 3--1+2, k--(k-1)+(k-2)
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i-1]+ dp[i-2];
        }
        return dp[n];
    }
};
// @lc code=end
