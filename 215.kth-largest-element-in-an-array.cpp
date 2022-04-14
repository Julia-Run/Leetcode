/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int tar = nums.size() - k;
        int lo = 0, hi = nums.size();
        int mid;
        while (lo + 1 < hi) // >=2个元素
        {
            mid = rankedIndex(nums, lo, hi);
            if (mid == tar)
                return nums[mid];
            else if (mid < tar)
                lo = mid + 1;
            else
                hi = mid;
        }
        return nums[lo]; // lo + 1 = hi, one element left
    }

    int rankedIndex(vector<int> &x, int lo, int hi)
    {
        int v = x[lo];
        int i = lo, j = hi;
        while (true)
        {
            while (x[++i] < v)
            {
                if (i >= hi - 1)
                    break;
            }
            while (v < x[--j])
            {
                if (j <= lo)
                    break;
            }
            if (i >= j)
                break;
            swap(x[i], x[j]);
        }
        swap(x[lo], x[j]);
        return j;
    }
};
// @lc code=end
