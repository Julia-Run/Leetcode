/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            for (auto &c : wordDict)
            {
                int le = c.size();
                // if (le <= i)
                //     dp[i] = dp[i - le] && s.substr(i - le, le) == c;
                // if (dp[i])
                //     break;
                if (le <= i && s.substr(i - le, le) == c)
                    dp[i] = dp[i] || dp[i-le];
            }
        }
        return dp[n];
    }
};
// @lc code=end
