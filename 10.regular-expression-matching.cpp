/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // init
        dp[0][0] = true;
        for (int i = 2; i <= n; ++i)
        {
            // first char in p must be . or a char, never a *
            if (p[i - 1] == '*') // current char to process
                dp[0][i] = dp[0][i - 2];
        }

        // dp;
        // m---i,s, n---j,p;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] != '*')
                    dp[i][j] = s[i - 1] == p[j - 1] && dp[i - 1][j - 1];
                else // p[j-1] = *
                {
                    if (p[j - 2] != '.' && s[i - 1] != p[j - 2])
                        // p---j-1, j-2 not work;
                        dp[i][j] = dp[i][j - 2];
                    else // p[j - 2] = '.' -- ..
                         // dp[i-1][j] --- s[i-1]==p[j-2]
                        dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
