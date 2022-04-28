/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> f(s.size() + 1, false);
        f[0] = true;
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = i - 1; j >= 0; --j) // start: j, length: i-j; find from small length;
            {
                if (f[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
                {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[s.size()];
    }
};
// @lc code=end
