/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    unordered_map<int, int> inIndex;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inIndex[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* helper(vector<int>& pre, int l1, int r1, vector<int>& in, int l2, int r2) {
        if (l1 > r1) return nullptr;
        int rootVal = pre[l1];
        int rootIndex = inIndex[rootVal];
        int leftSize = rootIndex - l2;
        TreeNode* root = new TreeNode(rootVal);
        root->left = helper(pre, l1 + 1, l1 + leftSize, in, l2, rootIndex - 1);
        root->right = helper(pre, l1 + leftSize + 1, r1, in, rootIndex + 1, r2);
        return root;
    }
};
// @lc code=end

