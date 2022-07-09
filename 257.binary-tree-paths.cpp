/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> paths;
        construct_paths(root, "", paths);
        return paths;
    }

    void construct_paths(TreeNode *root, string path, vector<string> &paths)
    {
        if (root == nullptr)
            return;
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {                          // 当前节点是叶子节点
            paths.push_back(path); // 把路径加入到答案中
            // path = "";  // why not necessary
            // return;
        }
        else
        {
            path += "->"; // 当前节点不是叶子节点，继续递归遍历
            construct_paths(root->left, path, paths);
            construct_paths(root->right, path, paths);
        }
    }
};
// @lc code=end
