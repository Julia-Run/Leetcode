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
        // 'O' connected with edges remain, else 'O' to 'X';
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) // cols
        {
            dfs(board, i, 0, m, n);
            dfs(board, i, n - 1, m, n);
        }
        for (int j = 0; j < n; ++j)
        {
            dfs(board, 0, j, m, n);
            dfs(board, m - 1, j, m, n);
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'T')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>> &board, int r, int c, int m, int n)
    {
        // return
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;
        if (board[r][c] != 'O')
            return;
        board[r][c] = 'T';
        dfs(board, r + 1, c, m, n);
        dfs(board, r - 1, c, m, n);
        dfs(board, r, c + 1, m, n);
        dfs(board, r, c - 1, m, n);
    }
};
// @lc code=end
