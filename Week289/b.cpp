class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        map<int, int> m;
        int mf = 0;
        for (auto x : tasks)
            mf = max(mf, ++m[x]);

        vector<vector<int>> st(mf + 1);
        for (auto x : m)
            st[x.second].push_back(x.first);
        if (st[1].size() != 0)
            return -1;
        int sum = 0;
        for (int i = 2; i <= mf; ++i)
        {
            int n = st[i].size();
            int local_sum = 0;
            if (n != 0)
            {
                local_sum += (i / 6) * 2;
                int k = i % 6;
                if (k == 0)
                    ;
                else if (k == 4 || k == 5)
                    local_sum += 2;
                else
                    local_sum += 1;
                sum += n * local_sum;
            }
        }
        return sum;
    }
};