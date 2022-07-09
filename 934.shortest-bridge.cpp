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
                if (grid[i][j])
                {
                    dfs(q, grid, i, j);
                    find = true;
                }
            }
        }

        int step = 0;
        while (!q.empty()) // fifo
        {
            int s = q.size(); // layer 1
            while (s--)       //
            {
                auto [r, c] = q.front();
                q.pop();
                vector<int> delta{1, 0, -1, 0, 1};
                for (int k = 0; k < 4; ++k)
                {
                    int rn = r + delta[k], cn = c + delta[k + 1];
                    if (rn >= 0 && rn < m && cn >= 0 && cn < n)
                    {
                        if (grid[rn][cn] == 1)
                            return step;
                        else if (grid[rn][cn] == 0)
                        {
                            grid[rn][cn] = 2;
                            q.push({rn, cn});
                        }
                    }
                }
            }
            ++step;
        }
        return -1;
    }

    void dfs(queue<pair<int, int>> &q, vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if (grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        q.push({i, j});
        dfs(q, grid, i + 1, j);
        dfs(q, grid, i - 1, j);
        dfs(q, grid, i, j + 1);
        dfs(q, grid, i, j - 1);
    }
};
// @lc code=end
