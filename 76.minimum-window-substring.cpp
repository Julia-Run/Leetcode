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

        // substring --> have to be ordered
        // drop one single element from the start then find from end

        // 1. deal with chars in t;
        vector<bool> flag(128, false);
        vector<int> charNumsT(128, 0);
        for (auto c : t)
        {
            flag[c] = true;
            ++charNumsT[c];
        }

        // lo to drop from start, minLo for easy output;
        // n for if counting how many chars of t are included in sub;
        int lo = 0, start = 0, minSize = s.size() + 1, n = 0;

        for (int hi = 0; hi < s.size(); ++hi)
        {
            // 02. include all chars of t in 1st sub
            if (flag[s[hi]])
            {
                if (--charNumsT[s[hi]] >= 0)
                    // key 01: why have to be >= 0?
                    // if three are 4 "A" in s, 2 "A" in t, currently iniV = 2;
                    // A1, v=1,++n; A2,v=0,++n; A3,v=-1; A4,v=-2;
                    ++n;
            }

            // when all chars included
            while (n == t.size())
            {
                // 03. log & refresh current minSize and start
                if (hi - lo + 1 < minSize)
                {
                    minSize = hi - lo + 1;
                    start = lo;
                }
                // 04. drop one single element (must be in t) from lo
                if (flag[s[lo]])
                {
                    if (++charNumsT[s[lo]] > 0)
                        --n;
                    // key 01: iniV = -2; 4A in current sub, 2A in t;
                    // drop: A1,v=-1; A2, v=0;---2A in sub---;A3,v=1>0,lost 1A, --n;
                    // the 2nd conditions
                }
                ++lo;
            }
        }
        return minSize > s.size() ? "" : s.substr(start, minSize);
    }
};
// @lc code=end
