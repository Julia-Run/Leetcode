/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution
{
public:
    bool validPalindrome(string s)
    {
        // string, defalt order
        // at most one char can be remove
        int lo = 0, hi = s.size() - 1;
        while (lo < hi)
        {
            if (s[lo] == s[hi])
            {
                ++lo;
                --hi;
            }
            else
            {
                return check(s, lo, hi - 1) || check(s, lo + 1, hi);
            }
        }
        // lo==hi && never return before
        return true;
    }
    bool check(string s, int lo, int hi)
    {
        while (lo < hi)
        {
            if (s[lo] == s[hi])
            {
                --hi;
                ++lo;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
