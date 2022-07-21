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
        vector<vector<bool>> row(9, vector<bool>(9, false)), col(9, vector<bool>(9, false)), box(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    int k = board[i][j] - '1';
                    row[i][k] = true;
                    col[j][k] = true;
                    box[i / 3 * 3 + j / 3 % 3][k] = true;
                }
                else
                    q.push_back({i, j});
            }
        }
        bool solved = false;
        dfs(0, board, row, col, box, q, solved);
    }

    void dfs(int k, vector<vector<char>> &board, vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<bool>> &box, vector<pair<int, int>> &q, bool &solved)
    {
        if (k == q.size())
        {
            solved = true;
            return;
        }

        auto [x, y] = q[k];
        for (int val = 0; val < 9 && !solved; ++val)
        {
            if (!row[x][val] && !col[y][val] && !box[x / 3 * 3 + y / 3 % 3][val])
            {
                row[x][val] = col[y][val] = box[x / 3 * 3 + y / 3 % 3][val] = true;
                board[x][y] = '1' + val;
                dfs(k + 1, board, row, col, box, q, solved);
                row[x][val] = col[y][val] = box[x / 3 * 3 + y / 3 % 3][val] = false;
                // board[x][y] = '.';
            }
        }
    }
};
// class Solution
// {
// public:
//     void solveSudoku(vector<vector<char>> &board)
//     {
//         vector<vector<bool>> row(9, vector<bool>(9, false)), col(9, vector<bool>(9, false)), box(9, vector<bool>(9, false));
//         for (int i = 0; i < 9; ++i)
//         {
//             for (int j = 0; j < 9; ++j)
//             {
//                 if (board[i][j] != '.')
//                 {
//                     int k = board[i][j] - '1';
//                     row[i][k] = true;
//                     col[j][k] = true;
//                     box[i / 3 * 3 + j / 3 % 3][k] = true;
//                 }
//             }
//         }
//         bool solved = false;
//         dfs(0, 0, board, row, col, box, solved);
//     }

//     void dfs(int x, int y, vector<vector<char>> &board, vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<bool>> &box, bool &solved)
//     {
//         if (y == 9)
//         {
//             y = 0;
//             x++;
//             if (x == 9)
//             {
//                 solved = true;
//                 return;
//             }
//         }

//         if (board[x][y] != '.')
//             dfs(x, y + 1, board, row, col, box, solved); // wrong!

//         for (int val = 0; val < 9 && !solved; ++val)
//         {
//             if (!row[x][val] && !col[y][val] && !box[x / 3 * 3 + y / 3 % 3][val])
//             {
//                 row[x][val] = col[y][val] = box[x / 3 * 3 + y / 3 % 3][val] = true;
//                 board[x][y] = '1' + val;
//                 dfs(x, y + 1, board, row, col, box, solved);
//                 row[x][val] = col[y][val] = box[x / 3 * 3 + y / 3 % 3][val] = false;
//                 // board[x][y] = '.';
//             }
//         }
//     }
// };
// @lc code=end
