/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // array: strs. array weight: 0,1; W: m, n; max: subsets;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // init
        for (auto &s : strs)
        {
            // count o and a in s;
            int c0 = s.size(), c1 = 0;
            for (auto x : s)
            {
                if (x == '1')
                {
                    --c0;
                    ++c1;
                }
            }

            // refresh dp
            for (int i = m; i - c0 >= 0; --i)
            {
                for (int j = n; j - c1 >= 0; --j)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - c0][j - c1]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
