/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // min sum of the path; right, down;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if (i == 0 && j != 0)
                    dp[0][j] = dp[0][j - 1] + grid[0][j];
                else if (j == 0 && i != 0)
                    dp[i][0] = dp[i - 1][0] + grid[i][0];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
