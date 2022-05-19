class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        if (words.size() == 1)
            return words;

        map<char, int> m;
        for (char c : words[0])
            ++m[c];

        int i = 1;
        while (i < words.size())
        {
            map<char, int> comp;
            for (char c : words[i])
                ++comp[c];
            if (m == comp)
                words.erase(words.begin() + i);
            else
            {
                m = comp;
                ++i;
            }
        }
        return words;
    }
};