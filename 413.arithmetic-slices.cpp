/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        // max nums of arrays with dx is equal; min: 3
        // why dp?
        // 3-1, 4-2, 5-0, 6-1, 7-2, 8-3;
        // dp[i-1] + 1;
        int n = nums.size();
        if (n < 3)
            return 0;
        vector<int> dp(n, 0);
        for (int i = 2; i < n; ++i)
        {
            if (nums[i] + nums[i - 2] == nums[i - 1] * 2)
                dp[i] = dp[i - 1] + 1;
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
// @lc code=end
