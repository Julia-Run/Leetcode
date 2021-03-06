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
        // one child at most one cookie;
        // size: g>=1, s>=0;
        // s[i] >= g[i];
        // max child;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j])
                ++i;
            ++j;
        }
        return i;
    }
};
// @lc code=end
