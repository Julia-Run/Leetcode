/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // size >= 2
        // 1 <= index1 < index2 <= numbers.length
        //sorted numbers
        // assume exactly one solution
        int lo = 0, hi = numbers.size()-1;
        int sum;
        while (lo < hi)
        {
            sum = numbers[lo] + numbers[hi];
            if (sum==target) break;
            else if (sum < target) ++lo;
            else --hi;
        }
        return vector<int>{lo+1, hi+1};
    }
};
// @lc code=end

