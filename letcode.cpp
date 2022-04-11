class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        if (matches.size() == 1)
        {
            vector<vector<int>> a;
            a.push_back(matches[0][0]);
            a.push_back(matches[0][1]);
            return a;
        }
        sort(matches.begin(), matches.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        vector<int> flags(100001, false);
        vector<int> nums(100001, 0);
        vector<int> one;
        for (int i = 0; i < matches.size(); ++i)
        {
            flags[matches[i][1]] = true;
            ++nums[matches[i][1]];
        }
        // deal with boundaries to get one
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 1)
                one.push_back(i);
        }
        // to find wins;
        sort(matches.begin(), matches.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        vector<int> win;
        int pre = -1;
        for (auto &x : matches)
        {
            if (flags[x[0] == true] && x[0] != pre)
            {
                win.push_back(x[0]);
                pre = x[0];
            }
        }
        // output
        vector<vector<int>> res = {win, one};
        return res;
    }
};