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
        int maxf = 0;
        for (int i : nums)
        {
            maxf = max(maxf, ++m[i]); // maxf --- to be used as len of a vector;
        }

        vector<vector<int>> f2v(maxf + 1);
        for (auto &x : m)
        {
            f2v[x.second].push_back(x.first);
        }

        vector<int> res;
        for (int i = maxf; i >= 0 && res.size() < k; --i)
        {
            for (int x : f2v[i])
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
