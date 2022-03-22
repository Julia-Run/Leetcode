/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int mi = m - 1, ni = n - 1, j = m + n - 1;
        while (mi >= 0 && ni >= 0)
        {
            nums1[j--] = nums1[mi] > nums2[ni] ? nums1[mi--] : nums2[ni--];
        }
        while (ni >= 0)
        {
            nums1[j--] = nums2[ni--];
        }
    }
};
// @lc code=end
