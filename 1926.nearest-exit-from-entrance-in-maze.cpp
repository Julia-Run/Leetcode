/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> d(m, vector<int>(n, -1));
        d[entrance[0]][entrance[1]] = 0;
        q.push({entrance[0], entrance[1]});
        return bfs(maze, q, d);
    }

    int bfs(vector<vector<char>> &maze, queue<pair<int, int>> &q, vector<vector<int>> &d)
    {
        int m = maze.size(), n = maze[0].size();
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            vector<int> dr{1, 0, -1, 0}, dc{0, 1, 0, -1};
            for (int i = 0; i < 4; ++i)
            {
                int x = r + dr[i], y = c + dc[i];
                if (x >= 0 && y >= 0 && x < m && y < n && maze[x][y] != '+' && d[x][y] == -1)
                {
                    d[x][y] = d[r][c] + 1;
                    q.push({x, y});
                    if (x == 0 || y == 0 || x == m - 1 || y == n - 1)
                        return d[x][y];
                }
            }
        }
        return -1;
    }
};
// @lc code=end
