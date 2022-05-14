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
        if (nums.size() < 2)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        int tar = sum / 2, n = nums.size();
        vector<bool> dp(tar + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i)
        {
            int v = nums[i];
            for (int j = tar; j - v >= 0; --j)
            {
                if (dp[j - v])
                    dp[j] = true;
                // dp[j] = dp[j - v] || dp[j];
            }
        }
        return dp[tar];
    }
};
// @lc code=end
