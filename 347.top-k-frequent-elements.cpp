/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> m;
        int maxF = 0;
        for (auto x : nums)
            maxF = max(maxF, ++m[x]);

        vector<vector<int>> rankedF(maxF + 1);
        for (auto &x : m)
        {
            rankedF[x.second].push_back(x.first);
        }

        vector<int> res;
        for (int i = maxF; i >= 0 && res.size() < k; --i)
        {
            for (auto x : rankedF[i])
            {
                res.push_back(x);
                if (res.size() == k)
                    break;
            }
        }
        return res;
    }
};
// @lc code=end
