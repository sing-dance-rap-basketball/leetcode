/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// p 0 1 2 3
//         *fast
//   *slow
// p 1 2
//     *fast
// *slow
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *h = new ListNode(0);
        h->next = head;
        ListNode *fast = h;
        ListNode *slow = h;

        for(int i=0; i<n; i++) {
            fast = fast->next;
        }
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return h->next;
    }
};

