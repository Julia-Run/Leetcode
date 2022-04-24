class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        map<int, int> v;
        int m = nums.size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < nums[i].size(); ++j)
                ++v[nums[i][j]];
        }
        vector<int> res;
        for (auto &x : v)
        {
            if (x.second == m)
                res.push_back(x.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
};