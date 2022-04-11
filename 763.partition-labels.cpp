/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        // size: s>=1, s<=500
        // greedy; string: defalt order
        // pos: last time a char appears;
        // using char as new index, log its pos;
        vector<int> last(26, -1);
        for (int i = 0; i < s.size(); ++i)
        {
            last[s[i] - 'a'] = i;
        }
        // current sub: log pos_max(all chars)
        // current i meet pos_max --> end;
        vector<int> res;
        int maxPos = -1, pre = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            maxPos = max(last[s[i] - 'a'], maxPos);
            if (i == maxPos)
            {
                res.push_back(maxPos - pre);
                pre = maxPos;
            }
        }
        return res;
    }
};
// @lc code=end
