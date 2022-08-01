/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67]x
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        vector<int> x, y;
        for (int i = a.size() - 1; i >= 0; --i)
            x.push_back(a[i] - '0');
        for (int i = b.size() - 1; i >= 0; --i)
            y.push_back(b[i] - '0');

        vector<int> c = add(x, y);
        string s = "";
        for (int i = c.size() - 1; i >= 0; --i)
            s += (c[i] + '0');
        return s;
    }

    vector<int> add(vector<int> &a, vector<int> &b)
    {
        if (a.size() < b.size())
            return add(b, a);
        vector<int> c;
        int t = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            t += a[i];
            if (i < b.size())
                t += b[i];
            c.push_back(t % 2);
            t /= 2;
        }
        if (t)
            c.push_back(1);
        return c;
    }
};
// @lc code=end
