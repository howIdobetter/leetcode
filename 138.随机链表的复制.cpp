/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        for (Node *node = head; node; node = node->next->next) {
            Node *nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        for (Node *node = head; node; node = node->next->next) {
            Node *nodeNew = node->next;
            nodeNew->random = node->random ? node->random->next : nullptr;
        }
        Node *headNew = head->next;
        for (Node *node = head; node; node = node->next) {
            Node *nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = nodeNew->next ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};
// @lc code=end

