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
                ans = max(ans, dfs(grid, i, j));
        }
        return ans;
    }

    int dfs(vector<vector<int>> &grid, int row, int cul)
    {
        int m = grid.size(), n = grid[0].size();
        if (row >= 0 && row < m && cul >= 0 && cul < n)
        {
            if (grid[row][cul] == 0)
                return 0;
            else
            {
                grid[row][cul] = 0;
                return 1 + dfs(grid, row + 1, cul) + dfs(grid, row, cul + 1) + dfs(grid, row - 1, cul) + dfs(grid, row, cul - 1);
            }
        }
        else
            return 0;
    }
};
// @lc code=end
