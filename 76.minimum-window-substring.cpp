/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        // to find mini substring of s which includes all chars in t
        // substring: lost one char in head, find one in the tail. --- find min
        vector<bool> flag(128, false);
        vector<int> charSum(128, 0);
        // preparation
        for (int i = 0; i < t.size(); ++i)
        {
            flag[t[i]] = true;
            ++charSum[t[i]];
        }
        // to do the job
        int countT = 0, lo = 0, start = 0, minSize = s.size() + 1;
        for (int hi = 0; hi < s.size(); ++hi)
        {
            if (flag[s[hi]])
            {
                if (--charSum[s[hi]] >= 0)
                    ++countT;
            }
            // when all chars included in s
            while (countT == t.size())
            {
                // refresh minSize
                if (hi - lo + 1 < minSize)
                {
                    start = lo;
                    minSize = hi - lo + 1;
                }
                // lose one char in head, break while;
                if (flag[s[lo]] && ++charSum[s[lo]] > 0)
                {
                    --countT;
                }
                ++lo;
            }
        }
        return minSize > s.size() ? "" : s.substr(start, minSize);
    }
};
// @lc code=end
