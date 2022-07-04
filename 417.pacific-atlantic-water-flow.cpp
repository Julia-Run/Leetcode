/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
        {
            dfs(heights, p, i, 0, 0);
            dfs(heights, a, i, n - 1, 0);
        }
        for (int j = 0; j < n; ++j)
        {
            dfs(heights, p, 0, j, 0);
            dfs(heights, a, m - 1, j, 0);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (p[i][j] && a[i][j])
                    ans.emplace_back(vector<int>{i, j});
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>> &h, vector<vector<bool>> &marked, int i, int j, int val)
    {
        int m = h.size(), n = h[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        if (marked[i][j])
            return;
        if (h[i][j] < val)
            return;
        marked[i][j] = true;
        dfs(h, marked, i + 1, j, h[i][j]);
        dfs(h, marked, i - 1, j, h[i][j]);
        dfs(h, marked, i, j + 1, h[i][j]);
        dfs(h, marked, i, j - 1, h[i][j]);
    }
};
// @lc code=end
