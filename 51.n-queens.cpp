/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> q(n, -1); // init
        vector<vector<string>> res;
        dfs(q, res, n, 0);
        return res;
    }

    void dfs(vector<int> &q, vector<vector<string>> &res, int n, int row)
    {
        // return: boundaries and fullfil
        if (row == n)
        {
            vector<string> temp;
            for (int i = 0; i < n; ++i)
            {
                string s(n, '.');
                for (int j = 0; j < n; ++j)
                {
                    if (j == q[i])
                        s[j] = 'Q';
                }
                temp.emplace_back(s);
            }
            res.emplace_back(temp);
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            q[row] = i;
            // column; key = q[row]
            bool good = true;
            for (int j = 0; j < row; ++j)
            {
                if (q[j] == q[row] || abs(j - row) == abs(q[j] - q[row]))
                    good = false;
            }
            // intersection line
            // for (int k = 0; k< n; ++k)
            // {
            //     if (abs(k - row) == abs(q[k] - q[row]))
            //         good = false;
            // }
            if (good)
                dfs(q, res, n, row + 1);
            q[row] = -1;
        }
    }
};
// @lc code=end
