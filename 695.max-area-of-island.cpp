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
        //   local union max value -- four direction
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>> &map, int i, int j)
    {
        int m = map.size(), n = map[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;
        if (map[i][j] == 0)
            return 0;
        map[i][j] = 0;
        return 1 + dfs(map, i + 1, j) + dfs(map, i - 1, j) + dfs(map, i, j + 1) + dfs(map, i, j - 1);
    }
};
// @lc code=end
