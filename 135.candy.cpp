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
        // consider the children rating as a function
        // left-to -right, keep increase & R-to-L, keep increase
        // for [a-1, a,a,..., a,a,a-1], keep the second and last second ---largest
        // between them, keep same and smallest candies
        // child >= 1;
        // init: one candy each child
        int n = ratings.size();
        // temp
        if (n < 2)
        {
            return 1;
        }
        vector<int> candies(n, 1);
        // L-to-R;
        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i - 1] < ratings[i]) // without "="
                candies[i] = candies[i - 1] + 1;
        }
        // R-to-L
        for (int i = ratings.size() - 1; i > 0; --i)
        {
            if (ratings[i - 1] > ratings[i] && candies[i - 1] < candies[i] + 1)
                candies[i - 1] = candies[i] + 1;
        }
        return accumulate(candies.begin(), candies.end(), 0); 
    }
};
// @lc code=end
