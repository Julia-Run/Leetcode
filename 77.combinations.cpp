/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        if (n < k)
            return ans;
        vector<int> temp;
        dfs(temp, 0, 1, k, n, ans);
        return ans;
    }

    void dfs(vector<int> &temp, int layer, int startVal, int k, int n, vector<vector<int>> &ans)
    {
        if (layer == k)
        {
            ans.emplace_back(temp);
            return;
        }
        for (int i = startVal; i <= n; ++i)
        {
            temp.emplace_back(i);
            dfs(temp, layer + 1, i + 1, k, n, ans);
            temp.pop_back();
        }
    }
};
// @lc code=end
