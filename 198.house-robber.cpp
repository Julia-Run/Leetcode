/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        vector<int> res(n);
        res[0] = nums[0], res[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i)
        {
            res[i] = max(res[i - 1], res[i - 2] + nums[i]);
        }
        return res[n-1];
    }
};
// @lc code=end
