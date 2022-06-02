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
        // A -- n A
        // copy all, paste
        // dp -- using previous state
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = i;
            for (int j = 2; 2 * j <= i; ++j)
            {
                if (i % j == 0)
                {
                    // copy j + past: i/j-1 -- 1+i/j-1
                    // copy i/j, past: j-1;  --1+j-1
                    dp[i] = dp[i / j] + j;
                    // dp[i] = dp[j] + i/j;  // not right
                    // dp[i] = min(dp[j] + i / j, dp[i]); // 2 * j <= i, no break
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end
