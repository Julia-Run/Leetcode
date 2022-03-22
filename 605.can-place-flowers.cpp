/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        // 0 0 0 ... 0 1 -- 0element_size=n, flower = n/2
        // 1 0 0 ... 0 1 -- 0element_size=n, flower = (n-1)/2
        // 1 0 0 ... 0 0 -- 0element_size=n, flower = n/2
        // 0 0 ... 0 0 0 -- 0element_size=n, flower = (n+1)/2
        // flowerbed >= 1, n >= 0
        if (n == 0)
            return true;
        int pre = -1, total = 0;
        // 遇到1，计算局部最优
        int s = flowerbed.size();
        for (int i = 0; i < s; ++i)
        {
            if (flowerbed[i] == 1)
            {
                if (pre < 0)
                    total += i / 2; // start
                // 0 0 0 ... 0 1 -- 0element_size=n, flower = n/2
                else
                    total += (i - pre - 2) / 2;
                // 1 0 0 ... 0 1 -- 0element_size=n, flower = (n-1)/2
                if (total >= n)
                    return true;
                pre = i;
            }
        }
        // f[s-1] = 1, total = total
        // f[s-1] = 0, f[pre] = 1, total += (s-1-pre)/2;
        // f[s-1] = 0, pre = -1, total += (s-pre)/2;
        if (flowerbed[s - 1] == 0)
        {
            if (pre == -1)
                total += (s - pre) / 2;
            // 0 0 ... 0 0 0 -- 0element_size=n, flower = (n+1)/2
            else
                total += (s - 1 - pre) / 2;
            // 1 0 0 ... 0 0 -- 0element_size=n, flower = n/2
        }
        return total >= n;
    }
};
// @lc code=end
