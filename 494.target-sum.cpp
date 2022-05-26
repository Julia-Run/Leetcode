/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // (sum - a) - a = tar --> a = (sum-tar)/2
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum < target || (sum - target) % 2 == 1)
            return 0;
        if (n == 1 && nums[0] == target)
            return 1;
        int t = (sum - target) / 2;

        // sum = t, how many dombinations
        vector<int> dp(t + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            int v = nums[i - 1];
            for (int j = t; j >= v; --j)
                dp[j] = dp[j - v] + dp[j];
        }
        return dp[t];
    }
};
// @lc code=end
