class Solution
{
public:
    int percentageLetter(string s, char letter)
    {
        int d = s.size();
        int num = 0;
        for (char i : s)
        {
            if (i == letter)
                ++num;
        }
        return (int)num * 1.0 / d * 100;
    }
};