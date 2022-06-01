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
        // 2d, bag, how to relate? -- dp[1][0]
        // with strs increase, refresh dp;
        int sum = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int k = 0; k < sum; ++k)
        {
            vector<int> cur = help(strs[k]);
            int c0 = cur[0], c1 = cur[1];
            for (int i = m; i >= c0; --i)
            {
                for (int j = n; j >= c1; --j)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - c0][j - c1]);
                }
            }
        }
        return dp[m][n];
    }
    vector<int> help(string &s)
    {
        int n = s.size();
        int c0 = n, c1 = 0;
        for (auto c : s)
        {
            if (c == '1')
            {
                --c0;
                ++c1;
            }
        }
        return vector<int>{c0, c1};
    }
};
// @lc code=end
