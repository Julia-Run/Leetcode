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

        vector<vector<char>> temp(9, vector<char>(9, '.'));
        vector<pair<int, int>> bag;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    bag.push_back({i, j});
            }
        }
        dfs(board, bag, 0);
    }

    bool dfs(vector<vector<char>> &all, vector<pair<int, int>> &bag, int k)
    {
        if (k == bag.size())
            return true;

        for (int i = 0; i < 9; ++i)
        {
            auto [r, c] = bag[k];
            char v = '1' + i;
            all[r][c] = v;
            bool good = true;
            for (int j = 0; j < 9; ++j)
            {
                if ((j != c && all[r][j] == v) || (j != r && all[j][c] == v))
                    good = false;
            }
            int posx = r / 3 * 3, posy = c / 3 * 3;
            for (int x = posx; x < posx + 3; ++x)
            {
                for (int y = posy; y < posy + 3; ++y)
                {
                    if (x != r && y != c && all[x][y] == v)
                        good = false;
                }
            }
            if (good && dfs(all, bag, k + 1))
                return true;
            all[r][c] = '.';
        }
        return false;
    }
};
// @lc code=end
