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
        vector<int> pos(n, -1); // rank question
        vector<vector<string>> ans;
        dfs(ans, pos, n, 0);
        return ans;
    }

    void dfs(vector<vector<string>> &ans, vector<int> &pos, int n, int row)
    {
        // return if row==n;
        if (row == n)
        {
            vector<string> temp;
            for (int i = 0; i < n; ++i)
            {
                string s(n, '.');
                if (pos[i] >= 0)
                    s[pos[i]] = 'Q';
                temp.emplace_back(s);
            }
            ans.emplace_back(temp);
            return;
        }
        // deal with current row and deep into row+1;
        for (int i = 0; i < n; ++i)
        {
            // change
            pos[row] = i;
            bool good = true;
            for (int j = 0; j < row; ++j)
            {
                if (pos[j] == pos[row] || abs(j - row) == abs(pos[j] - pos[row]))
                    good = false;
            }
            // if go to nexyu row
            if (good)
                dfs(ans, pos, n, row + 1);
            // go back or do nothing
            pos[row] = -1;
        }
    }
};
// @lc code=end
