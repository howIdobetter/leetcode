/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
private:
    unordered_map<long long, long long> m;
public:
    int pathSum(TreeNode* root, long long targetSum) {
        if (!root) return 0;
        m[0] = 1;
        return dfs(root, 0, targetSum);
    }

    long long dfs(TreeNode* node, long long cSum, long long tSum) {
        if (!node) return 0;
        cSum += node->val;
        long long res = 0;
        if (m.find(cSum - tSum) != m.end()) {
            res += m[cSum - tSum];
        }
        m[cSum]++;
        res += dfs(node->left, cSum, tSum) + dfs(node->right, cSum, tSum);
        m[cSum]--;
        return res;
    }
};

// @lc code=end

