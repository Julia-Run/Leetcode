/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
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
            if (dp.back() < nums[i])
                dp.push_back(nums[i]);
            else
            {
                auto x = lower_bound(dp.begin(), dp.end(), nums[i]); 
                *x = nums[i];
            }
        }
        return dp.size();
    }
};
// @lc code=end
