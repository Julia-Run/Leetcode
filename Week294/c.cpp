class Solution
{
public:
    int minimumLines(vector<vector<int>> &stockPrices)
    {
        int n = stockPrices.size();
        if (n <= 2)
            return n - 1;
        // sort by day
        sort(stockPrices.begin(), stockPrices.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        // dp---min lines
        int dp = 1;
        long long day, price;
        long long dayPre = stockPrices[1][0] - stockPrices[0][0];
        long long pricePre = stockPrices[1][1] - stockPrices[0][1];
        vector<int> pre = stockPrices[0];
        for (int i = 2; i < n; ++i)
        {
            vector<int> now = stockPrices[i];
            day = now[0] - pre[0], price = now[1] - pre[1];
            if (day * pricePre != price * dayPre)
                dp++;
            dayPre = day;
            pricePre = price;
            pre = now;
        }
        return dp;
    }
};