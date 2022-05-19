/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
class Solution
{
public:
    int minSteps(int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = i;
            for (int j = 2; j * j <= i; ++j)
            {
                if (i % j == 0)
                {
                    int m = i/j;  
                    dp[i] = dp[m] + j; // j = j-1+1
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end
