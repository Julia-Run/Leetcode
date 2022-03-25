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
        // bed>=1, n >=0
        // meet 1, start caculating current flowers
        // -1000...0001,  0:x; flowers: x/2
        // 1000...0001,  0:x, flowers: (x-1)/2
        // 1000...000,  0:x, flowers: x/2
        // 000...000,  0:x, flowers: (x+1)/2
        if (n == 0)
            return true;
        int pre = -1; // index of current start (-1 to f.size()-1)
        int sum = 0;
        for (int i = 0; i < flowerbed.size(); ++i)
        {
            if (flowerbed[i] == 1)
            {
                if (pre == -1)
                    sum += i / 2; // start state: meet 1, nums of "0"= i;
                else
                    sum += (i - pre - 2) / 2; // i-pre+1-2-1
                pre = i;
            }
            if (sum >= n)
                return true;
        }
        if (flowerbed[flowerbed.size() - 1] == 0)
        {
            if (pre == -1)
                sum += (flowerbed.size() + 1) / 2;
            else
                sum += (flowerbed.size() - pre - 1) / 2; // s-1(index)-pre+1-1
        }
        return sum >= n;
    }
};
// @lc code=end
