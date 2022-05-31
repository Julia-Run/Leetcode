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
        // 1D dp; 1<=n<=45;how many ways
        // why this is dp; related to i-1, i-2;
        // I can find a relation between them
        // 0-1, 1-1,2-2;-- ;dp[i-1] + dp[i-2]
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n]; 
    }
};
// @lc code=end
