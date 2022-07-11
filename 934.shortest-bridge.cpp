/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// @lc code=start
class Solution
{
public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        bool find = false;
        for (int i = 0; i < m && !find; ++i)
        {
            for (int j = 0; j < n && !find; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, q, i, j);
                    find = true;
                }
            }
        }

        int step = 0;
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                auto [r, c] = q.front();
                q.pop();
                vector<int> delta{1, 0, -1, 0, 1};
                for (int k = 0; k < 4; ++k)
                {
                    int rn = r + delta[k], cn = c + delta[k + 1];
                    // effective
                    if (rn >= 0 && cn >= 0 && rn < m && cn < n)
                    {
                        if (grid[rn][cn] == 1)
                            return step;            // find;
                        else if (grid[rn][cn] == 0) //  add to next step
                        {
                            grid[rn][cn] = 2;
                            q.push({rn, cn});
                        } // if == 2, continue;
                    }
                }
            }
            ++step; // next layer;
        }
        return -1;
    }

    void dfs(vector<vector<int>> &grid, queue<pair<int, int>> &q, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        if (grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        q.push({i, j});
        dfs(grid, q, i + 1, j);
        dfs(grid, q, i - 1, j);
        dfs(grid, q, i, j + 1);
        dfs(grid, q, i, j - 1);
    }
};
// @lc code=end
