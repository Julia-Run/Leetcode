/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int i = 0; i < n; ++i)
        {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'T')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>> &board, int i, int j)
    {
        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        if (board[i][j] == 'X' || board[i][j] == 'T')
            return;
        board[i][j] = 'T';
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
};
// @lc code=end
