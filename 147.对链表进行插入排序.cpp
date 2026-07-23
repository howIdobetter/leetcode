/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *curr = head->next;
        ListNode *lastSorted = head;
        while (curr) {
            if (lastSorted->val <= curr->val) {
                lastSorted = curr;
            } else {
                ListNode *prev = dummyNode;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }
        ListNode *ans = dummyNode->next;
        delete dummyNode;
        return ans;
    }
};
// @lc code=end

