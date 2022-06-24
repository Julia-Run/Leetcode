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
        vector<vector<bool>> p(m, vector<bool>(n, false)), a(m, vector<bool>(n, false));
        // start from four edges to decide if reachable;
        for (int i = 0; i < m; ++i)
        {
            dfs(heights, i, 0, p);     // left;
            dfs(heights, i, n - 1, a); // right
        }
        for (int j = 0; j < n; ++j)
        {
            dfs(heights, 0, j, p);     // top
            dfs(heights, m - 1, j, a); // bottom
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (p[i][j] && a[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }

    // for p or a, if reacheable: true, else: false (unchanged)
    void dfs(vector<vector<int>> &h, int i, int j, vector<vector<bool>> &reach)
    {
        int m = h.size(), n = h[0].size();
        // if (i < 0 || i >= m || j < 0 || j >= n)
        //     return;
        if (reach[i][j])
            return; // key!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! otherwise, overflow.
        reach[i][j] = true;
        vector<vector<int>> dx = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int k = 0; k < 4; ++k)
        {
            int x = i + dx[k][0], y = j + dx[k][1];
            if (x >= 0 && x < m && y >= 0 && y < n && h[x][y] >= h[i][j])
                dfs(h, x, y, reach);
        }
    }

    // vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    // {
    //     int m = heights.size(), n = heights[0].size();
    //     vector<vector<bool>> p(m, vector<bool>(n, false)), a(m, vector<bool>(n, false));
    //     // start from four edges to decide if reachable;
    //     for (int i = 0; i < m; ++i)
    //     {
    //         dfs(heights, i, 0, 0, p);     // left;
    //         dfs(heights, i, n - 1, 0, a); // right
    //     }
    //     for (int j = 0; j < n; ++j)
    //     {
    //         dfs(heights, 0, j, 0, p);     // top
    //         dfs(heights, m - 1, j, 0, a); // bottom
    //     }
    //     vector<vector<int>> ans;
    //     for (int i = 0; i < m; ++i)
    //     {
    //         for (int j = 0; j < n; ++j)
    //         {
    //             if (p[i][j] && a[i][j])
    //                 ans.push_back({i, j});
    //         }
    //     }
    //     return ans;
    // }

    // void dfs(vector<vector<int>> &h, int i, int j, int val, vector<vector<bool>> &reach)
    // {
    //     int m = h.size(), n = h[0].size();
    //     if (i < 0 || i >= m || j < 0 || j >= n)
    //         return;
    //     if (reach[i][j])
    //         return;
    //     if (h[i][j] < val)
    //         return;
    //     reach[i][j] = true;
    //     vector<vector<int>> dx = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    //     for (int k = 0; k < 4; ++k)
    //     {
    //         int x = i + dx[k][0], y = j + dx[k][1];
    //         dfs(h, x, y, h[i][j], reach);
    //     }
    // }
};

// @lc code=end
