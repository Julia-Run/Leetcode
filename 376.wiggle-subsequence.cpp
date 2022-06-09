/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return n;
        int pre = nums[1] - nums[0];
        int res = nums[1] - nums[0] == 0 ? 1 : 2;
        for (int i = 2; i < n; ++i)
        {
            int cur = nums[i] - nums[i - 1];
            if (pre * cur < 0 || pre == 0 && cur != 0)
            {
                ++res;
                pre = cur;
            }
        }
        return res;
    }
};
// @lc code=end
