/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // how many unions;
        int m = isConnected.size();
        vector<bool> marked(m, false);
        int count = 0;
        for (int i = 0; i < m; ++i)
        {
            if (!marked[i])
            {
                dfs(isConnected, marked, i, m); //
                ++count;
            }
        }
        return count;
    }

    void dfs(vector<vector<int>> &isConnected, vector<bool> &marked, int i, int m)
    {
        if (marked[i])
            return;
        marked[i] = true;
        int n = isConnected[i].size();
        for (int j = 0; j < n; ++j)
        {
            if (isConnected[i][j] == 1)
                dfs(isConnected, marked, j, m);
        }
    }
};
// @lc code=end
