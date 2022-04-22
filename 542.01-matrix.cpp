/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX - 1));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (mat[i][j] == 0)
                    dp[i][j] = 0; // init for dp[i][j]
                else              // renew: l-to-r, top-to-bottom;
                {
                    if (j > 0)
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    if (i > 0)
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                }
            }
        }

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                if (dp[i][j] != 0)
                { // renew: bottom-to-top, r-to-l
                    if (j < m - 1)
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    if (i < n - 1)
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                }
            }
        }
        return dp;
    }
};
// @lc code=end