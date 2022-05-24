/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        else if (n == 2)
            return max(nums[0], nums[1]);
        else
            return max(he(nums, 0, n - 1), he(nums, 1, n));
    }
    int he(vector<int> &bag, int s, int e)
    {
        int left = bag[s], mid = max(bag[s], bag[s + 1]);
        for (int i = s + 2; i < e; ++i)
        {
            int temp = mid;
            mid = max(mid, left + bag[i]);
            left = temp;
        }
        return mid;
    }
};
// @lc code=end
