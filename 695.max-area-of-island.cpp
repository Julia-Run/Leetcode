/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>> &grid, int ri, int cj)
    {
        int m = grid.size(), n = grid[0].size();
        if (ri >= 0 && ri < m && cj >= 0 && cj < n)
        {
            if (grid[ri][cj] == 0)
                return 0;
            else
            {
                grid[ri][cj] = 0;
                return 1 + dfs(grid, ri + 1, cj) + dfs(grid, ri - 1, cj) + dfs(grid, ri, cj + 1) + dfs(grid, ri, cj - 1);
            }
        }
        else
            return 0;
    }
};
// @lc code=end
