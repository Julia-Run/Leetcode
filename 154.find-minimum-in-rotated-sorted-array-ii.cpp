/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (r > 0 && nums[r] == nums[0])
            r--;
        if (nums[r] >= nums[0]) return nums[0]; 
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[0])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l];
    }
};
// @lc code=end
