/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        vector<int> a, b;
        for (int i = num1.size() - 1; i >= 0; --i)
            a.push_back(num1[i] - '0');
        for (int i = num2.size() - 1; i >= 0; --i)
            b.push_back(num2[i] - '0');

        vector<int> c(a.size() + b.size() + 10, 0);
        for (int i = 0; i < a.size(); ++i)
        {
            for (int j = 0; j < b.size(); ++j)
            {
                c[i + j] += a[i] * b[j];
            }
        }

        for (int i = 0; i + 1 < c.size(); ++i)
        {
            c[i + 1] += c[i] / 10;
            c[i] = c[i] % 10;
        }

        while (c.size() > 1 && c.back() == 0)
            c.pop_back();

        string s = "";
        for (int i = c.size() - 1; i >= 0; --i)
            s += c[i] + '0';
        return s;
    }
};
// @lc code=end
