class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        int n = special.size();
        sort(special.begin(), special.end());
        int m = 0;
        for (int i = 1; i < n; ++i)
        {
            if (special[i] - special[i - 1] >= 2)
                m = max(special[i] - special[i - 1] - 1, m);
        }
        if (special[0] - bottom >= 2)
            m = max(special[0] - bottom, m);
        if (top - special[n - 1] >= 2)
            m = max(top - special[n - 1], m);
        return m;
    }
};