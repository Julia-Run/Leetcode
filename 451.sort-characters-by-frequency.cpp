/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> m;
        int maxf = 0;
        for (auto x : s)
            maxf = max(maxf, ++m[x]);

        vector<vector<char>> v(maxf + 1);
        for (auto x : m)
        {
            v[x.second].push_back(x.first);
        }

        string res = "";
        for (int i = maxf; i >= 0; --i)
        {
            for (auto c : v[i])
            {
                for (int j = i; j > 0; --j)
                    res += c;
            }
        }
        return res;
    }
};
// @lc code=end
