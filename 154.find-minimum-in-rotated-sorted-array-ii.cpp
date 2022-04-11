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
        // size >=1, int
        int lo = 0, hi = nums.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (mid > 0 && nums[mid - 1] > nums[mid])
                return nums[mid];
            if (nums[mid] > nums[hi - 1])
                lo = mid + 1;
            else if (nums[mid] < nums[hi - 1])
                hi = mid;
            else
                --hi;
        }
        return nums[lo];
    }
};
// @lc code=end
