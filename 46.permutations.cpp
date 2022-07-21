/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size(); // total layers;
        vector<vector<int>> res;
        vector<bool> used(n, false);
        vector<int> path(n, 0);
        int u = 0;
        dfs(u, path, used, nums, res);
        return res;
    }

    void dfs(int u, vector<int> &path, vector<bool> &used, vector<int> &nums, vector<vector<int>> &res)
    {
        if (u == nums.size())
        {
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!used[i])
            {
                used[i] = true;
                path[u] = nums[i];
                dfs(u + 1, path, used, nums, res);
                used[i] = false;
            }
        }
    }
};
// @lc code=end
