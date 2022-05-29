class Solution
{
public:
    int totalSteps(vector<int> &nums)
    {
        int n = nums.size(); // n>=1;
        if (n < 2)
            return 0;
        int r, l, res = 0, pre = 0;
        bool loop = false;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i - 1] > nums[i])
            { // init
                loop = true;
                r = nums[i - 1];
                l = nums[i];
                res = 0;
            }
            if (loop && nums[i] >= l && nums[i] < r)
                ++res;
            else if (nums[i] >= r) // new loop
            {
                loop = false;
                pre = max(pre, res);
            }
        }
        pre = max(pre, res);
        return pre;
    }
};