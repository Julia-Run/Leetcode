/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] /
 */

// @lc code=start
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        // size: k>=1, int
        // diffrent situation; binary search
        int lo = 0, hi = nums.size(); // [ );
        int mid;
        while (lo < hi) // when while ends, lo=hi;
        {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[lo] < nums[mid]) // hi = mid;
            {
                if (nums[lo] <= target && target < nums[mid])
                    hi = mid; // normal BS
                else
                    lo = mid + 1;
            }
            else if (nums[lo] > nums[mid])
            {
                if (nums[mid] < target && target <= nums[hi - 1])
                    lo = mid + 1;
                else
                    hi = mid;
            }
            else
                ++lo;
        }
        return false;
        // key : target must be [nums[lo], nums[hi])
    }
};
// @lc code=end
