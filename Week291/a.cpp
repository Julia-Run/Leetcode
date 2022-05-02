class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        vector<string> all;
        int i = 0;
        for (; i < number.size(); ++i)
        {
            if (number[i] == digit)
            {
                string x = number;
                // x.replace(number.begin() + i, number.begin() + i + 1, 1, '0');
                x.erase(i, 1);
                all.push_back(x);
            }
            else
                continue;
        }
        string res = all[0];
        for (auto y : all)
        {
            if (y > res)
                res = y;
        }
        return res;
    }
};