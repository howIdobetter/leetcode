/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    using pti = pair<TreeNode*, int>;
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        int cnt = 0;
        vector<int> result;
        queue<pti> q;
        q.push({root, cnt});
        cnt++;
        while (!q.empty()) {
            bool flag = true;
            while (q.front().second == cnt - 1) {
                auto entry = q.front();
                q.pop();
                auto node = entry.first;
                if (flag) {
                    result.push_back(node->val);
                    flag = false;
                }
                if (node->right) {
                    q.push({node->right, cnt});
                }
                if (node->left) {
                    q.push({node->left, cnt});
                }
            }
            cnt++;
        }
        return result;
    }
};
// @lc code=end

