/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<pair<int, int>> q;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    q.emplace_back({i, j});
            }
        }
        dfs(board, q, 0);
    }

    bool dfs(vector<vector<char>> &all, vector<pair<int, int>> &q, int k)
    {
        if (k == q.size())
            return true;

        for (int i = 0; i < 9; ++i)
        {
            char v = '1' + i;
            auto [r, c] = q[k];
            all[r][c] = v;
            bool good = true;
            // row col
            for (int j = 0; j < 9; ++j)
            {
                if ((j != r && all[j][c] == v) || (j != c && all[r][j] == v))
                    good = false;
            }
            // box
            int posx = r / 3 * 3, posy = c / 3 * 3;
            for (int x = posx; x < posx + 3; ++x)
            {
                for (int y = posy; y < posy + 3; ++y)
                {
                    if (x != r && y != c && all[x][y] == v)
                        good = false;
                }
            }

            if (good && dfs(all, q, k + 1))
                return true;
            all[r][c] = '.';
        }
        return false;
    }
};
// @lc code=end
