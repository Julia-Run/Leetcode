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
        // substring -- defalt order, drop one single element from head, search in tail
        // 01. predealing data in t;
        vector<bool> flag(128, false);
        vector<int> nums(128, 0);
        for (auto c : t)
        {
            flag[c] = true;
            ++nums[c];
        }

        // 02. drop one find one;
        int lo = 0, minSize = s.size() + 1, start = 0, n = 0;
        // n for check if all chars of t in substring
        for (int hi = 0; hi < s.size(); ++hi)
        {
            // 03. find start substring && later find new one for substring;
            if (flag[s[hi]] && --nums[s[hi]] >= 0)
                ++n;

            // when all chars included in substring
            while (n == t.size())
            {
                // 04. refresh minSize / start
                if (hi - lo + 1 < minSize)
                {
                    minSize = hi - lo + 1;
                    start = lo;
                }
                // drop one element
                if (flag[s[lo]] && ++nums[s[lo]] > 0)
                    --n;
                ++lo;
            }
        }
        return minSize > s.size() ? "" : s.substr(start, minSize);
    }
};
// @lc code=end
