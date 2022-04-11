class Solution
{
public:
    int largestInteger(int num)
    {
        // 1<= num <= 10^9
        string s = to_string(num);
        int a, m, b, max;
        for (int i = 0; i < s.size(); ++i)
        {
            a = s[i];
            m = s[i] % 2;
            max = i;
            for (int j = i + 1; j < s.size(); ++j)
            {
                if (s[j] % 2 == m and s[j] > s[max])
                    max = j;
            }
            if (i != max)
            {
                int temp = s[i];
                s[i] = s[max];
                s[max] = temp;
            }
        }
        int res = stoi(s);
        return res;
    }
};