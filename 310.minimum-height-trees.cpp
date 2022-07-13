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
        // 突破点：将所有只有一个邻居的节点视为叶子节点
        // 假设只有一个邻居的节点不是叶子节点，则必是根节点，不可能为其他节点，其他节点的邻居都不只1个，如果让其做根节点，则必然会增加树的深度
        // 建图
        if (n == 1)
            return {0};
        if (n == 2)
            return {0, 1};
        vector<vector<int>> g(n);  // edges
        vector<int> degrees(n, 0); // how many edges; for leaves, degree = 1;
        vector<bool> visited(n, false);
        for (auto e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            ++degrees[e[0]];
            ++degrees[e[1]];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (degrees[i] == 1)
            {
                q.push(i);
                visited[i] = true;
            }
        } // init q to keep leaves in it;
        queue<int> ans = q;
        while (!q.empty())
        {
            queue<int> nq;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto nx_node : g[node]) // leaves
                {
                    if (!visited[nx_node]) // go up
                    {
                        --degrees[nx_node]; // move previous level leaves;
                        if (degrees[nx_node] == 1)
                        {
                            visited[nx_node] = true;
                            nq.push(nx_node);
                        }
                    }
                }
            }
            q = nq;                         // keep one layer nodes;
            ans = nq.size() > 0 ? nq : ans; // if nq is empty; previous layer is the answer;
        }

        vector<int> res;
        while (!ans.empty())
        {
            res.push_back(ans.front());
            ans.pop();
        }
        return res;
    }
};
// @lc code=end
