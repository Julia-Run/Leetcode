/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return false;

        // 1d, dp, sum = half;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        // bag;
        int t = sum / 2;
        vector<bool> dp(t + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            int cur = nums[i - 1];
            for (int j = t; j >= cur; --j) // sequence;
                dp[j] = dp[j - cur] || dp[j];
        }
        return dp[t];
    }
};
// @lc code=end
