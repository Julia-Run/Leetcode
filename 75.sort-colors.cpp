/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        for (int i = 0; i <= r;)
        {
            if (nums[i] == 2)
                swap(nums[i], nums[r--]);
            else if (nums[i] == 0)
                swap(nums[i++], nums[l++]);
            else
                ++i;
        }
    }
};
// @lc code=end
