/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // at most one cookies. max numbers of childen content
        // size: g >= 1, s >= 0
        // rank g & s, diliver cookies
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0; // i for g, j for s
        // find how many kid content
        while (i < g.size() & j < s.size())
        {
            if (g[i]<=s[j]) ++i; 
            ++j; 
        }
        return i; 
    }
};
// @lc code=end
