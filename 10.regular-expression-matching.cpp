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
        // dp, 2d, using p to match s;
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        // if p is empty, no match; dp[j][0] = false, no need to init;
        // if s is empty; of * = 0 can match;
        // first letter in p can not be *
        for (int i = 2; i <= n; ++i)
        {
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2];
        }

        // dp[i][j] -- if s[0 to i-1] can be matched by p[0 to j-1];
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // state change to T only when they match
                // case 1: s[i-1]=p[j-1] or p[j-1]=.
                // if char not eaqul, alse;
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                // case2: p[j-1]='*', not = s[i-1], but have chance to match
                else if (p[j - 1] == '*')
                {
                    // previous can be a char or .
                    // case2a: pre = char, but not eaqul s[i-1], * = 0 , useless;
                    if (p[j - 2] != '.' && p[j - 2] != s[i - 1])
                        dp[i][j] = dp[i][j - 2]; // state transfer
                    // pre=s[i-1] or pre=. : s[i-1] is matched;
                    // state transfer: s[i-2] match; or * = 0, expired;
                    else
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
