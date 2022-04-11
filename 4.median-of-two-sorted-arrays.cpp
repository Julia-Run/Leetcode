/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // size: nums1>=0, nums2>=0, m+n>=1;
        // boundaries?
        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        if (total % 2 == 1)
            return find(nums1, 0, nums2, 0, total / 2 + 1);
        else
            return (find(nums1, 0, nums2, 0, total / 2) +
                    find(nums1, 0, nums2, 0, total / 2 + 1)) /
                   2.0;
    }

    int find(vector<int> &nums1, int start1, vector<int> &nums2, int start2, int k)
    {
        // include start1 and strt2
        int s1 = nums1.size(), s2 = nums2.size();
        if (s1 - start1 > s2 - start2)
            return find(nums2, start2, nums1, start1, k);
        if (s1 - start1 < 1)
            return nums2[start2 + k - 1];
        // end
        if (k <= 1)
            return min(nums1[start1], nums2[start2]);
        // recursion
        int k1 = min(k / 2, s1 - start1), k2 = k - k1;
        int i = start1 + k1 - 1, j = start2 + k2 - 1; // one extra;
        if (nums1[i] == nums2[j])
            return nums1[i];
        if (nums1[i] < nums2[j])
            return find(nums1, i + 1, nums2, start2, k2);
        else
            return find(nums2, j + 1, nums1, start1, k1);
    }
};
// @lc code=end
