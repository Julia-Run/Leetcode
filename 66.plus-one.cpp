/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> c;
        int t = 1; 
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            t += digits[i];
            c.push_back(t%10);
            t /= 10; 
        }
        if (t) c.push_back(1);
        reverse(c.begin(), c.end());
        return c; 
    }
};
// @lc code=end
