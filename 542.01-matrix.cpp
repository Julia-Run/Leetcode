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
        // nearest 0 for each cell;
        // 2D; dp--min distance to 0;
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    // if (i == 0 && j != 0)
                    //     dp[0][j] = min(dp[0][j - 1] + 1, dp[0][j]);
                    // else if (j == 0 && i != 0)
                    //     dp[i][0] = min(dp[i][0], dp[i - 1][0] + 1);
                    // else if (i == 0 && j == 0)
                    //     ;
                    // else
                    //     dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]) + 1, dp[i][j]);
                    if (i > 0)
                        dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
                    if (j > 0)
                        dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
                }
            }
        }

        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (i < m - 1)
                    dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
                if (j < n - 1)
                    dp[i][j] = min(dp[i][j + 1] + 1, dp[i][j]);
            }
        }
        return dp;
    }
};
// @lc code=end