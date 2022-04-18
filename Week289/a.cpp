class Solution
{
public:
    string digitSum(string s, int k)
    {
        int n = s.size();
        if (n <= k)
            return s;
        string res; 
        while (n > k)
        {
            res = "";
            for (int i = 0; i < n; i += k)
            {
                int sum = 0;
                for (int j = i; j < i + k && j < n; ++j)
                {
                    sum += s[j] - 48;
                }
                res += to_string(sum);
            }
            n = res.size();
            s = res;
        }
        return res;
    }
};