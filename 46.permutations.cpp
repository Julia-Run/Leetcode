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
        int m = nums.size();
        vector<vector<int>> ans;
        dfs(nums, 0, 0, m, ans);
        return ans;
    }

    void dfs(vector<int> &nums, int layer, int startIndex, int m, vector<vector<int>> &ans)
    {
        if (layer == m)
        {
            ans.emplace_back(nums);
            return;
        }
        for (int j = startIndex; j < m; ++j)
        {
            swap(nums[j], nums[layer]);
            dfs(nums, layer + 1, startIndex + 1, m, ans);
            swap(nums[layer], nums[j]);
        }
    }
};
// @lc code=end
