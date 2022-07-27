/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        long l = 0, r = long(x);
        long mid; 
        while (l < r)
        {
            mid = l + (r - l + 1) / 2;
            if (mid*mid <= x)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};
// @lc code=end
