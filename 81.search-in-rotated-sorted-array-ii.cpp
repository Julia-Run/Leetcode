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
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid]==target) return true;
            if (nums[l] < nums[mid])
            {
                if (nums[mid] > target && target >= nums[l])
                    r = mid;
                else
                    l = mid + 1;
            }
            else if (nums[l] > nums[mid])
            {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid;
            }
            else
                ++l;
        }
        return nums[l] == target;
        // return false; 
    }
};
// @lc code=end
