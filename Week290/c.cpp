class Solution
{
public:
// error, some case not include
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {
        sort(rectangles.begin(), rectangles.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] > b[0]; });
        vector<int> x;
        for (auto &i : points)
        {
            int count = 0;
            for (auto &j : rectangles)
            {
                if (i[0] > j[0])
                    break;
                ++count;
            }
            x.push_back(count);
        }

        sort(rectangles.begin(), rectangles.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] > b[1]; });
        vector<int> y;
        for (auto &i : points)
        {
            int count = 0;
            for (auto &j : rectangles)
            {
                if (i[1] > j[1])
                    break;
                ++count;
            }
            y.push_back(count);
        }

        vector<int> r;
        for (int i = 0; i < x.size(); ++i)
            r.push_back(min(x[i], y[i]));
        return r;
    }
};