/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (i == 0)
                    dp[0][j] = j;
                else if (j == 0)
                    dp[i][0] = i;
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i - 1][j - 1] + 2);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
