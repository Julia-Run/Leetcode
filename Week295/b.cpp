class Solution
{
public:
    int totalSteps(vector<int> &nums)
    {
        int n = nums.size(); // n>=1;
        if (n < 2)
            return 0;
        int r, l, res = 0, pre = 0;
        int online = 0;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i - 1] > nums[i])
            { // init
                r = max(nums[i - 1], online);
                l = nums[i];
                pre = max(pre, res);
                res = 0;
            }
            if (nums[i] >= l && nums[i] < r)
                ++res;
            else if (nums[i] >= r) // new loop
            {
                online = nums[i];
                pre = max(pre, res);
            }
        }
        pre = max(pre, res);
        return pre;
    }
};