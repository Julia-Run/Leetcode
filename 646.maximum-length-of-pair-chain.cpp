/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int n = pairs.size();
        // vector<int> dp(n + 1, 0);
        // dp[0] = 1;
        // vector<int> pre = pairs[0];
        // for (int i = 1; i < n; ++i)
        // {
        //     vector<int> v = pairs[i];
        //     if (v[0] > pre[1])
        //     {
        //         dp[i] = dp[i - 1] + 1;
        //         pre = v;
        //     }
        //     else
        //         dp[i] = dp[i - 1];
        // }
        // return dp[n - 1];]
        int res = 1, pre = pairs[0][1];
        for (int i = 1; i < n; ++i)
        {
            if (pairs[i][0] > pre)
            {
                ++res;
                pre = pairs[i][1]; 
            }
        }
        return res;
    }
};
// @lc code=end
