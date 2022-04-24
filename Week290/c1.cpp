class Solution
{
public:
// runtime error
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {
        sort(rectangles.begin(), rectangles.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] > b[0]; });
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        vector<int> x;
        for (auto &i : points)
        {
            if (i[0] > rectangles[0][0])
                break;
            int count = 0;
            for (auto &j : rectangles)
            {
                if (i[0] > j[0])
                    break;
                else
                {
                    if (i[1] <= j[1])
                        ++count;
                }
            }
            x.push_back(count);
        }
        while (x.size() < points.size())
            x.push_back(0);
        return x;
    }
};