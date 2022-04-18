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
        int maxF = 0;
        for (auto x : s)
            maxF = max(maxF, ++m[x]);

        vector<vector<char>> basket(maxF + 1);
        for (auto &x : m)
            basket[x.second].push_back(x.first);

        string res = "";
        for (int i = maxF; i >= 0; --i)
        {
            for (auto x : basket[i])
            {
                for (int j = i; j > 0; --j)
                    res += x;
            }
        }
        return res;
    }
};
// @lc code=end
