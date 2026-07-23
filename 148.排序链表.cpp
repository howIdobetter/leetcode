/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        int length = 0;
        ListNode* node = head;
        while (node) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next; i++) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; subLength && curr && curr->next; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode dummyNode, *tail = &dummyNode,
        *temp1 = head1, *temp2 = head2;
        while (temp1 && temp2) {
            if (temp1->val < temp2->val) {
                tail->next = temp1;
                temp1 = temp1->next;
            } else {
                tail->next = temp2;
                temp2 = temp2->next;
            }
            tail = tail->next;
        }
        tail->next = temp1 ? temp1 : temp2;
        return dummyNode.next;
    }
};
// @lc code=end

