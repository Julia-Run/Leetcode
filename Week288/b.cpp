// 3 <= expression.length <= 10
// expression consists of digits from '1' to '9' and '+'.
// expression starts and ends with digits.
// expression contains exactly one '+'.
class Solution
{
public:
    string minimizeResult(string expression)
    {
        int k for (int i = 0; i < expression.size(); ++i)
        {
            if (i == "+")
            {
                k = i;
                break;
            }
        }
        string l = expression.substr(0, k), r = expression.substr(k + 1, expression.size());
        string res;
        int n = l.size() - r.size();
        while (n != 0)
        {
            if (n > 0)
            {
                int i = 1;
                while (i <= n)
                {
                    int limit = power(10, l.size() - 1);
                    string subl = l.substr(i, l.size());
                    int a = stoi(subl), b = stoi(r);
                    if ((a + b) < limit)
                    {
                        res = l.substr(0, i) + '(' + subl + '+' + r + ')';
                        return res;
                    }
                    else
                        ++i;
                }
            }
            else
            {
                int i = r.size() - 1;
                while (i <= abs(n))
                {
                    int limit = power(10, r.size() - 1);
                    string subl = l.substr(0, i);
                    int a = stoi(l), b = stoi(surbl);
                    if ((a + b) < limit)
                    {
                        res = '(' + l + '+' + surbl + ')' + r.substr(i, r.size());
                        return res;
                    }
                    else
                        --i;
                }
            }
        }
        int j = 0;
        while(j < l.size())
        {
            // int k = (l[j] - 48) * (r[r.size() - j] - 48);
            int limit = power(10, l.size() - j - 1);
            int a = l.substr(j + 1, l.size()), b = r.substr(0, r.size() - j - 1);
            if ((a + b) < limit)
            {
                res = l[j] + '(' + to_string(a) + '+' + to_string(b) + ')' + r[r.size() - j - 1];
                return res;
            }
            ++j;
        }
    }
};