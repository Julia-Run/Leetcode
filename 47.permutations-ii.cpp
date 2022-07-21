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
        // ranking; dfs;
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> marked(nums.size(), false);
        int u = 0;
        sort(nums.begin(), nums.end());
        dfs(u, path, marked, res, nums);
        return res;
    }
    void dfs(int u, vector<int> &path, vector<bool> &marked, vector<vector<int>> &res, vector<int> &nums)
    {
        if (u == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!marked[i])
            {
                if (i > 0 && nums[i] == nums[i - 1] && !marked[i - 1])
                    continue;
                path.push_back(nums[i]);
                marked[i] = true;
                dfs(u + 1, path, marked, res, nums);
                path.pop_back();
                marked[i] = false;
            }
        }
    }
};
// @lc code=end
