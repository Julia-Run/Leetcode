class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int n = rocks.size();
        vector<int> fill(n, 0);
        for (int i = 0; i < n; ++i)
            fill[i] = capacity[i] - rocks[i];
        sort(fill.begin(), fill.end());
        int i = 0;
        for (; i < n && additionalRocks >= 0; ++i)
        {
            additionalRocks -= fill[i];
        }
        if (additionalRocks < 0)
            --i;
        return i;
    }
};