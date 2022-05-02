class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        map<int, int> m;
        for (int i = 0; i < cards.size(); ++i)
        {
            ++m[cards[i]];
        }
        vector<int> all;
        for (auto i : cards)
        {
            if (m[i] < 2)
                continue;
            auto s = find(cards.begin(), cards.end(), i);
            while (m[i] >= 1)
            {
                auto e = find(s + 1, cards.end(), i);
                int d = e - s + 1;
                all.push_back(d);
                s = e;
                --m[i];
            }
        }
        if (all.size() == 0)
            return -1;
        int res = all[0];
        for (auto x : all)
        {
            if (x > res)
                res = x;
        }
        return res;
    }
};