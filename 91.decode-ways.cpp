/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        // '12' max ways to decodes
        // dp; why? related to previous one in different situations;
        // 1,2,3,4,5,6,7,8,9;  10,11,12,13,14,15,16,17,18,19; 20,21,22,23,24,25,26;
        if (s[0] == '0')
            return 0;

        // now first char is not 0
        int n = s.size();
        if (n < 2)
            return 1;

        // now 1st != 0; n>=2;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            int j = i - 1;
            //check by setting j-1: 0, 1,2,3~9
            if (s[j] == '0')
            {
                if (s[j - 1] == '1' || s[j - 1] == '2')
                    dp[i] = dp[i - 2];
                else
                    return 0;
            }
            else if ((s[j - 1] == '1' && s[j] != '0') || (s[j - 1] == '2' && s[j] != '0' && s[j] - '0' <= 6))
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
        }
        return dp[n];
    }
};
// @lc code=end
