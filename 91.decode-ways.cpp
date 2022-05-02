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
        // s>=1; 0-9
        if (s[0] - '0' == 0)
            return 0;
        // first one is not zero;
        int n = s.size();
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i)
        {
            if (s[i - 1] - '0' == 0)
            {
                if (s[i - 2] - '0' == 0 || s[i - 2] - '0' >= 3)
                    return 0; // invalid;
                else
                    dp[i] = dp[i - 2]; // i have to combine with i-1 as a unity;
            }
            else
            {
                if (s[i - 2] - '0' == 1 || (s[i - 2] - '0' == 2 && s[i - 1] - '0' <= 6))
                    dp[i] = dp[i - 2] + dp[i - 1]; // can combine or not combine
                else
                    dp[i] = dp[i - 1]; // can not combine;
            }
        }
        return dp[n];
    }
};
// @lc code=end
