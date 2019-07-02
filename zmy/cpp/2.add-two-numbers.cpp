/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int acc = 0;
        while (l1 != nullptr || l2 != nullptr || acc != 0) {
            p->next = new ListNode(0);
            p = p->next;
            if (l1 != nullptr) {
                acc += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                acc += l2->val;
                l2 = l2->next;
            }
            p->val = acc % 10;
            acc /= 10;
        }
        return head -> next;

    }
};

