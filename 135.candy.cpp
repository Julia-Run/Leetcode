/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        // size: ratings >=1;
        // greedy: smallest candies;
        int n = ratings.size();
        vector<int> c(n, 1);
        for (int i = 1; i < n; ++i)
        {
            if (ratings[i] > ratings[i - 1])
                c[i] = c[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1] && c[i] <= c[i + 1])
                c[i] = c[i + 1] + 1;
        }
        return accumulate(c.begin(), c.end(), 0);
    }
};
// @lc code=end
