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
        // ranking; reppeated
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> vis(n, 0);
        vector<int> temp;
        dfs(nums, res, vis, temp, 0, n);
        return res;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &vis, vector<int> &temp, int layer, int n)
    {
        if (layer == n)
        {
            res.emplace_back(temp);
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            if (vis[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) // vis[i-1] already done
                continue;
            vis[i] = 1;
            temp.push_back(nums[i]);
            dfs(nums, res, vis, temp, layer + 1, n);
            vis[i] = 0;
            temp.pop_back();
        }
    }
};
// @lc code=end
