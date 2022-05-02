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
        // top left to bottom right, then reverse
        // during the way, i-1, j-1 has been updated, so you can use safely;
        int m = mat.size(), n = mat[0].size(); // >=1
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 0)
                    dp[i][j] = mat[i][j]; // initially set all 0;
                if (j > 0)                // refresh
                    dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
                if (i > 0)
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
            }
        }

        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (j < n - 1)
                    dp[i][j] = min(dp[i][j + 1] + 1, dp[i][j]);
                if (i < m - 1)
                    dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
            }
        }
        return dp;
    }
};
// @lc code=end
