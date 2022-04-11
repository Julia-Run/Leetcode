/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

// @lc code=start
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        // size >= 1
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                int lo = nums[i - 1], hi = nums[i];
                nums[i - 1] = hi;
                if (!check(nums))
                {
                    nums[i - 1] = lo;
                    nums[i] = lo;
                    return check(nums);
                }
                else
                    return true;
            }
        }
        return true;
    }
    bool check(vector<int> &a)
    {
        for (int lo = 0, hi = a.size() - 1; lo < hi; ++lo)
        {
            if (a[lo] > a[lo + 1])
                return false;
        }
        return true;
    }
    // 以下函数会改变nums；
    // bool check(vector<int> &a, int i, int delta)
    // {
    //     if (delta < 0)
    //         a[i - 1] = a[i];
    //     else
    //         a[i] = a[i - 1];
    //     for (int lo = 0, hi = a.size() - 1; lo < hi; ++lo)
    //     {
    //         if (a[lo] > a[lo + 1])
    //             return false;
    //     }
    //     return true;
};
// @lc code=end
