/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // size: nums>=0
        int n = nums.size();
        int l = left(nums, target, 0, n);
        int r = right(nums, target, 0, n);
        if (r >= l)
            return vector<int>{l, r};
        return vector<int>{-1, -1};
    }

    int right(vector<int> &a, int t, int lo, int hi)
    {
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] <= t)
                lo = mid + 1; // [start, lo )
            else
                hi = mid; // [hi, end)
        }
        return lo - 1; // -1,0,1,...
    }

    int left(vector<int> &a, int t, int lo, int hi)
    {
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] < t)
                lo = mid + 1; // [start, lo)
            else              // a[mid] >= t
                hi = mid;     // [hi, end) also [lo, end)
        }
        return lo; // 0,1,2,...
    }
};
// @lc code=end
