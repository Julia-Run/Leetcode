/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        if (accumulate(candidates.begin(), candidates.end(), 0) < target)
            return res;
        int curr = 0, layer = 0;
        vector<int> temp;
        dfs(candidates, res, temp, curr, layer, target);
        return res;
    }

    void dfs(vector<int> &all, vector<vector<int>> &res, vector<int> &temp, int curr, int layer, int t)
    {
        // if (temp.size() > all.size() || t < 0)
        //     return;  // size() condition won't happen
        if (t < 0)
            return;
        if (t == 0)
        {
            res.emplace_back(temp);
            return;
        }
        for (int i = curr; i < all.size(); ++i)
        {
            if (i > curr && all[i] == all[i - 1])
                continue;
            temp.emplace_back(all[i]); // 3,1a,1b,2; 3,1b,1c,2;
            dfs(all, res, temp, i + 1, layer + 1, t - all[i]);
            temp.pop_back();
        }
    }
};
// @lc code=end
