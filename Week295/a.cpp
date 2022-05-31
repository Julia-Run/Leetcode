class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        map<char, int> m;
        for (auto c : s)
            ++m[c];
        int n = 0;
        bool flag = true;
        while (flag)
        {
            for (auto x : target)
            {
                --m[x];
                if (m[x] < 0)
                {
                    flag = false;
                    --n;
                    break;
                }
            }
            ++n;
        }
        return n;
    }
};