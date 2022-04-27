/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n + 1, 1);
        int pre = s[0] - '0';
        for (int i = 2; i <= n; ++i)
        {
            int cur = s[i - 1] - '0';
            if (cur == 0)
            {
                if (pre == 0 || pre > 2)
                    return 0;
                else
                    dp[i] = dp[i - 2];
            }
            else
            {
                if ((pre == 1) || (pre == 2 && cur <= 6))
                    dp[i] = dp[i - 1] + dp[i - 2];
                else
                    dp[i] = dp[i - 1];
            }
            pre = cur;
        }
        return dp[n];
    }
};
// @lc code=end
