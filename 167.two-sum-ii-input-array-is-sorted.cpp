/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int lo = 0, hi = numbers.size() - 1;
        int sum;
        // in same sorted arry , lo < hi;
        while (lo < hi)
        {
            sum = numbers[lo] + numbers[hi];
            if (sum == target)
                break;
            else if (sum > target)
                --hi;
            else
                ++lo;
        }
        return vector<int>{lo + 1, hi + 1};
    }
};
// @lc code=end
