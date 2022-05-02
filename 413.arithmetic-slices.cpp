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
        if (nums.size() < 3)
            return 0;
        int n = nums.size();
        // dp[i]---an array end at current nums[i];
        // 0--0,1--0,2--if...1(0+1), 3--if...2(1+1), ...
        // currently n>=3;
        vector<int> dp(n, 0);
        for (int i = 2; i < n; ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] = dp[i - 1] + 1;
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
// @lc code=end
