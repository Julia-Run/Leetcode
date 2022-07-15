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
//         vector<vector<string>> res;
//         vector<int> row(n, -1);
//         vector<bool> col(n, false), dg(2 * n - 1, false), udg(2 * n - 1, false);
//         dfs(res, row, col, dg, udg, 0, n);
//         return res;
//     }

//     void dfs(vector<vector<string>> &res, vector<int> &row, vector<bool> &col, vector<bool> &dg, vector<bool> &udg, int k, int n)
//     {
//         if (k == n)
//         {
//             vector<string> temp;
//             for (int i = 0; i < n; ++i)
//             {
//                 string s(n, '.');
//                 if (row[i] >= 0)
//                     s[row[i]] = 'Q';
//                 temp.push_back(s);
//             }
//             res.push_back(temp);
//             return;
//         }

//         for (int i = 0; i < n; ++i)
//         {
//             if (!col[i] && !dg[k + i] && !udg[k - i + n])
//             {
//                 row[k] = i;
//                 col[i] = dg[k + i] = udg[k - i + n] = true;
//                 dfs(res, row, col, dg, udg, k + 1, n);
//                 col[i] = dg[k + i] = udg[k - i + n] = false;
//                 row[k] = -1;
//             }
//         }
//     }
// };
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> temp(n, string(n, '.'));
        vector<vector<string>> res;
        vector<bool> row(n, false), col(n, false), dg(2 * n - 1, false), udg(2 * n - 1, false);
        dfs(res, temp, row, col, dg, udg, 0, 0, n, 0);
        return res;
    }

    void dfs(vector<vector<string>> &res, vector<string> &temp, vector<bool> &row, vector<bool> &col, vector<bool> &dg, vector<bool> &udg, int x, int y, int n, int s)
    {
        if (y == n)
        {
            y = 0;
            x++;
        }
        if (x == n)
        {
            if (s == n)
                res.push_back(temp);
            return;
        }
        // not put queen 
        dfs(res, temp, row, col, dg, udg, x, y + 1, n, s);
        // put queen 
        if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
        {
            temp[x][y] = 'Q';
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
            dfs(res, temp, row, col, dg, udg, x, y + 1, n, s + 1);
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
            temp[x][y] = '.';
        }
    }
};
// @lc code=end
