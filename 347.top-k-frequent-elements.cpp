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
        // nums>=1; 1<=k<=nums.size();
        // find a vector<int> with kth largest elements
        map<int, int> m;
        int maxF = 0;
        for (auto x : nums)
        {
            maxF = max(maxF, ++m[x]);
        }

        vector<vector<int>> chain(maxF + 1);
        for (auto &x : m)
        {
            chain[x.second].push_back(x.first);
        }

        vector<int> res;
        for (int i = maxF; i >= 0 && res.size() < k; --i)
        {
            for (auto x : chain[i])
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
