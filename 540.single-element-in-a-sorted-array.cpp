/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        // n >= 3, odd number;
        // in case overflow;
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        // BS
        int lo = 0, hi = n - 1, mid;
        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2;
            // if (mid % 2 == 1 && nums[mid] == nums[mid - 1] || mid % 2 == 0 && nums[mid] == nums[mid + 1])
            if (nums[mid] == nums[mid ^ 1])
                lo = mid + 1;
            else
                hi = mid;
        }
        // lo = hi, not neccesirily = mid-1 or mid;
        // [s,lo), key is at the start point of this range [hi, e)
        return nums[lo];
    }
};

// class Solution
// {
// public:
//     int singleNonDuplicate(vector<int> &nums)
//     {
//         int n = nums.size();
//         int res = nums[0];
//         for (int i = 1; i<n; ++i) res ^= nums[i];  // 2^2 = 0;
//         return res;
//     }
// };
// @lc code=end
