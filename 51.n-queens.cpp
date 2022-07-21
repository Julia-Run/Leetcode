/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
// class Solution
// {
// public:
//     vector<vector<string>> solveNQueens(int n)
//     {
//         vector<int> path(n, -1);
//         vector<vector<string>> res;
//         vector<bool> col(n, false), dg(2 * n - 1, false), udg(2 * n - 1, false);
//         int u = 0;
//         dfs(u, path, col, dg, udg, n, res);
//         return res;
//     }
//     void dfs(int u, vector<int> &path, vector<bool> &col, vector<bool> &dg, vector<bool> &udg, int n, vector<vector<string>> &res)
//     {
//         if (u == n)
//         {
//             vector<string> temp;
//             for (int i = 0; i < n; ++i)
//             {
//                 string s(n, '.');
//                 if (path[i] >= 0)
//                     s[path[i]] = 'Q';
//                 temp.emplace_back(s);
//             }
//             res.emplace_back(temp);
//             return;
//         }

//         for (int i = 0; i < n; ++i)
//         {
//             if (!col[i] && !dg[u + i] && !udg[u - i + n])
//             {
//                 col[i] = dg[u + i] = udg[u - i + n] = true;
//                 path[u] = i;
//                 dfs(u + 1, path, col, dg, udg, n, res);
//                 col[i] = dg[u + i] = udg[u - i + n] = false;
//                 path[u] = -1;
//             }
//         }
//     }
// };

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> path(n, string(n, '.'));
        vector<vector<string>> res;
        vector<bool> row(n, false), col(n, false), dg(2 * n - 1, false), udg(2 * n - 1, false);
        int x = 0, y = 0, s = 0;
        dfs(x, y, s, path, row, col, dg, udg, n, res);
        return res;
    }
    void dfs(int x, int y, int s, vector<string> &path, vector<bool> &row, vector<bool> &col, vector<bool> &dg, vector<bool> &udg, int n, vector<vector<string>> &res)
    {
        if (y == n)
        {
            y = 0;
            ++x;
        }
        if (x == n)
        {
            if (s == n)
                res.emplace_back(path);
            return;
        }

        // not place
        dfs(x, y + 1, s, path, row, col, dg, udg, n, res);
        // place
        if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
        {
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
            path[x][y] = 'Q';
            dfs(x, y + 1, s + 1, path, row, col, dg, udg, n, res);
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
            path[x][y] = '.';
        }
    }
};
// @lc code=end
