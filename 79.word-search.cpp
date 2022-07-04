/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> marked(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, marked, i, j, m, n, word, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &marked, int i, int j, int m, int n,
             string word, int pos)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;
        if (marked[i][j] || board[i][j] != word[pos])
            return false;
        if (pos == word.size() - 1)
            return true;
        marked[i][j] = true;
        bool find = dfs(board, marked, i + 1, j, m, n, word, pos + 1) ||
                    dfs(board, marked, i - 1, j, m, n, word, pos + 1) ||
                    dfs(board, marked, i, j + 1, m, n, word, pos + 1) ||
                    dfs(board, marked, i, j - 1, m, n, word, pos + 1);
        marked[i][j] = false;
        return find;
    }
};
// @lc code=end
