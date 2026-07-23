/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxResult = INT_MIN;
        dfs(root, maxResult);
        return maxResult;
    }
    int dfs(TreeNode* node, int& maxResult) {
        if (!node) return 0;
        int left = max(0, dfs(node->left, maxResult));
        int right = max(0, dfs(node->right, maxResult));
        maxResult = max(maxResult, left + node->val + right);
        return node->val + max(left, right);
    }
};
// @lc code=end

