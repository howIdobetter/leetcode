/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode *start;
        if (list1->val <= list2->val) {
            start = list1;
            list1 = list1->next;
        } else {
            start = list2;
            list2 = list2->next;
        }
        ListNode *p = start;
        while (list1 || list2) {
            if (!list1) {
                p->next = list2;
                break;
            } else if(!list2) {
                p->next = list1;
                break;
            } else if (list1->val <= list2->val) {
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            } else {
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }
        }
        return start;
    }
};
// @lc code=end

