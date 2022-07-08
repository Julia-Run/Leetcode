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
        vector<int> colPos(n, -1);
        vector<vector<string>> ans;
        dfs(ans, colPos, n, 0);
        return ans;
    }

    void dfs(vector<vector<string>> &ans, vector<int> &colPos, int n, int row)
    {
        if (row == n)
        {
            // run to the end; update ans and return
            vector<string> temp;
            for (int i = 0; i < n; ++i)
            {
                string s(n, '.');
                if (colPos[i] >= 0)
                    s[colPos[i]] = 'Q';
                temp.emplace_back(s);
            }
            // for (int i = 0; i < n; ++i)
            // {
            //     string s(n, '.');
            //     for (int j = 0; j < n; ++j)
            //     {
            //         if (j == colPos[i])
            //             s[j] = 'Q';
            //     }
            //     temp.emplace_back(s);
            // }
            ans.emplace_back(temp);
            return;
        }

        // deal with current row and dive into row+1
        for (int i = 0; i < n; ++i)
        {
            colPos[row] = i;
            bool good = true;
            for (int j = 0; j < row; ++j)
            {
                if (colPos[j] == colPos[row] || abs(j - row) == abs(colPos[j] - colPos[row]))
                    good = false;
            }
            if (good)
                dfs(ans, colPos, n, row + 1);
            colPos[row] = -1;
        }
    }
};
// @lc code=end
