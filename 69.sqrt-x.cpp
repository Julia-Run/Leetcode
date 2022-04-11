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
        // x >= 0; -- long
        if (x == 0)
            return 0;
        long lo = 1, hi = (long)x + 1; // [ );
        long mid;
        while (lo < hi) // when while ends, lo=hi;
        {
            mid = lo + (hi - lo) / 2;
            if (mid <= x / mid)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo - 1;
    }
};
// @lc code=end
