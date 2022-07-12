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
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        if (accumulate(candidates.begin(), candidates.end(), 0) < target)
            return res;
        dfs(candidates, res, temp, 0, target);
        return res;
    }

    void dfs(vector<int> &candidates, vector<vector<int>> &res, vector<int> &temp, int k, int t)
    {
        if (temp.size() > candidates.size() || t < 0)
            return; // out of range
        if (t == 0)
        {
            res.emplace_back(temp);
            return; // find result;
        }
        for (int i = k; i < candidates.size(); ++i)
        {
            if (i > k && candidates[i] == candidates[i - 1]) // remove duplicated elements in same layer;
                continue;
            temp.emplace_back(candidates[i]);
            dfs(candidates, res, temp, i + 1, t - candidates[i]);
            temp.pop_back();
        }
    }
};
// @lc code=end
