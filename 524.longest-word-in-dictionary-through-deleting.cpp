/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */

// @lc code=start
class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        // s>=1,d>=1
        // only need to return string, no need to log index ...
        // fro each string in dic: 01, if can be from s by deleting some chars
        // key: all string have defalt order
        string res = ""; // ==s, will fail
        int max = 0;
        for (auto d : dictionary)
        {
            int di = 0, j = 0;
            while (di < d.size() && j < s.size())
            {
                if (s[j] == d[di])
                    ++di;
                ++j;
            }
            // if d can be from s, refresh
            if (di == d.size())
            {
                if (d.size() > max || (d.size() == max && d < res))
                {
                    res = d;
                    max = d.size();
                }
            }
        }
        return res;
    }
};
// @lc code=end
