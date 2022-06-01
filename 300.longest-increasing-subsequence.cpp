/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
// class Solution
// {
// public:
//     int lengthOfLIS(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> dp(n, 1);
//         int res = 0;
//         for (int i = 1; i < n; ++i)
//         {
//             int cur = nums[i]; // current nums element;
//             for (int j = 0; j < i; ++i)
//                 if (nums[j] < cur)
//                     dp[i] = max(dp[j] + 1, dp[i]);
//             res = max(res, dp[i]);
//         }
//         return res;
//     }
// };
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < n; ++i)
        {
            auto c = lower_bound(dp.begin(), dp.end(), nums[i]);
            if (c == dp.end())
                dp.push_back(nums[i]);
            else
                *c = nums[i];
        }
        return dp.size();
    }
};
// @lc code=end
