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
        int lo = 0, hi = s.size() - 1;
        while (lo < hi)
        {
            if (s[lo] == s[hi])
            {
                ++lo;
                --hi;
            }
            else
                // one chance: check if this is aba;
                return check(s, lo + 1, hi) || check(s, lo, hi - 1);
        }
        return true;
    }
    bool check(string s, int lo, int hi)
    {
        while (lo < hi)
        {
            if (s[lo] != s[hi])
                return false;
            ++lo;
            --hi;
        }
        return true;
    }
};
// @lc code=end
