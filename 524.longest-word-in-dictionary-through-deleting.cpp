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
        // any char in dic[i] can be find in s[j]  -- current min = dic[i]
        // by deleting some, but still ordered.
        int maxIndex = -1, maxSize = 0; // to refresh min
        for (int curr = 0; curr < dictionary.size(); ++curr)
        {
            // 01. for each element in dic, check if it can get from s;
            int si = 0, curri = 0;
            while (si < s.size() && curri < dictionary[curr].size())
            {
                if (s[si] == dictionary[curr][curri])
                    ++curri;
                ++si;
            }
            // 02. if it can get from s; refresh;
            if (curri == dictionary[curr].size())
            {
                if (dictionary[curr].size() > maxSize)
                {
                    maxSize = dictionary[curr].size();
                    maxIndex = curr;
                }
                else if (dictionary[curr].size() == maxSize)
                {
                    maxIndex = dictionary[curr] < dictionary[maxIndex] ? curr : maxIndex;
                }

                // longest length, smallest order;
            }
        }
        return maxSize == 0 ? "" : dictionary[maxIndex];
    }
};
// @lc code=end
