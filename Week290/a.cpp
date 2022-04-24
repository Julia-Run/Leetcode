class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            sort(nums[0].begin(), nums[0].end());
            return nums[0];
        }
        unordered_set<int> set1, set2;
        for (int i = 0; i < nums[0].size(); ++i)
            set1.insert(nums[0][i]);
        for (int i = 1; i < nums.size(); ++i)
        {
            set2.clear();
            for (int j = 0; j < nums[i].size(); ++j)
                set2.insert(nums[i][j]);
            set1 = helper(set1, set2);
        }
        vector<int> res;
        for (auto &x : set1)
            res.push_back(x);
        sort(res.begin(), res.end());
        return res;
    }

    unordered_set<int> helper(unordered_set<int> set1, unordered_set<int> set2)
    {
        if (set1.size() > set2.size())
            return helper(set2, set1);
        unordered_set<int> r;
        for (auto &i : set1)
        {
            if (set2.count(i))
                r.insert(i);
        }
        return r;
    }
};