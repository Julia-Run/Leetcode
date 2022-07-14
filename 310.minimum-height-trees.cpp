/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
// class Solution  // time limited;
// {
// public:
//     vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
//     {
//         if (n == 1)
//             return vector<int>{0};
//         unordered_map<int, vector<int>> child;
//         vector<int> height(n, 0);
//         for (auto e : edges)
//         {
//             child[e[0]].emplace_back(e[1]);
//             child[e[1]].emplace_back(e[0]);
//         }

//         for (int i = 0; i < n; ++i)
//         {
//             vector<bool> visited(n, false);
//             queue<int> q;
//             q.push(i);
//             visited[i] = true;
//             int count = -1;
//             while (!q.empty())
//             {
//                 ++count;
//                 int s = q.size();
//                 while (s--)
//                 {
//                     int v = q.front();
//                     q.pop();
//                     for (int w : child[v])
//                     {
//                         if (!visited[w])
//                         {
//                             visited[w] = true;
//                             q.push(w);
//                         }
//                     }
//                 }
//             }
//             height[i] = count;
//         }

//         vector<int> res;
//         vector<int> c = height;
//         sort(c.begin(), c.end());
//         int val = c[0];
//         for (int i = 0; i < n; ++i)
//         {
//             if (height[i] == val)
//                 res.push_back(i);
//         }
//         return res;
//     }
// };

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        vector<vector<int>> adj(n, vector<int>{});
        vector<int> degree(n, 0);
        for (vector<int> e : edges)
        {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
            ++degree[e[0]];
            ++degree[e[1]];
        }

        queue<int> q;
        vector<bool> vis(n, false);
        for (int v = 0; v < n; ++v)
        {
            if (degree[v] == 1)
            {
                q.push(v);
                vis[v] = true;
            }
        }

        queue<int> pre;
        while (!q.empty())
        {
            pre = q;
            int s = q.size();
            while (s--)
            {
                int v = q.front();
                q.pop();
                for (int w : adj[v])
                {
                    --degree[w];
                    if (!vis[w])
                    {
                        if (degree[w] == 1)
                        {
                            q.push(w);
                            vis[w] = true;
                        }
                    }
                }
            }
        }

        vector<int> ans;
        while (!pre.empty())
        {
            ans.emplace_back(pre.front());
            pre.pop();
        }
        return ans;
    }
};
// @lc code=end
