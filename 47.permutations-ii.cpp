/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> pending(nums.size(), 0);
        dfs(nums, res, pending, temp);
        return res;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &pending, vector<int> &temp)
    {
        if (temp.size() == nums.size())
        {
            res.emplace_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (pending[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !pending[i - 1])
                continue;
            pending[i] = 1;
            temp.emplace_back(nums[i]);
            dfs(nums, res, pending, temp);
            pending[i] = 0;
            temp.pop_back();
        }
    }
};
// @lc code=end
