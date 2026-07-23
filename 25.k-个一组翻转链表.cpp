/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail) {
        ListNode *prev = tail->next;
        ListNode *curr = head;
        while (prev != tail) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *prevTail = dummyNode;
        while (head) {
            ListNode *tail = prevTail;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return dummyNode->next;
                }
            }
            ListNode *nextHead = tail->next;
            auto result = reverseList(head, tail);
            head = result.first;
            tail = result.second;
            prevTail->next = head;
            head = nextHead;
            prevTail = tail;
        }
        ListNode *ans = dummyNode->next;
        delete dummyNode;
        return ans;
    }
};
// @lc code=end

