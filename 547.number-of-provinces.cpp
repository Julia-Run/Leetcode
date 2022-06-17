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
        int m = isConnected.size();
        int ans = 0;
        vector<bool> marked(m, false);
        for (int i = 0; i < m; ++i)
        {
            if (!marked[i])
            {
                dfs(isConnected, marked, i, m);
                ++ans;
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>> &isConnected, vector<bool> &marked, int x, int n)
    {
        marked[x] = true;
        for (int i = 0; i < n; ++i)
        {
            if (isConnected[x][i] == 1 && !marked[i])
                dfs(isConnected, marked, i, n);
        }
    }
};
// @lc code=end
