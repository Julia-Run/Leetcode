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
        // size: s>=1; d>=1;
        // out: longest || smallest order
        int max = 0;
        string res = "";
        for (auto &x : dictionary)
        {
            int j = 0;
            for (int i = 0; i < s.size() && j < x.size(); ++i)
            {
                if (s[i] == x[j])
                    ++j; // move j only if we can get j from s;
            }
            // if x can get from s
            if (j == x.size())
            {
                if (x.size() > max || x.size() == max && x < res)
                {
                    res = x;
                    max = x.size();
                }
            }
        }
        return res; 
    }
};
// @lc code=end
