/**
 * 21. Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */

/**
 * Runtime: 8 ms, faster than 85.83% of C++ online submissions for Merge Two Sorted Lists.
 * Memory Usage: 8.9 MB, less than 51.70% of C++ online submissions for Merge Two Sorted Lists.
 * 这程序写的 不美……
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        
        ListNode *tmp = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tmp->next = l1;
                l1 = l1->next;
                tmp = tmp->next;
            }
            else {
                tmp->next = l2;
                l2 = l2->next;
                tmp = tmp->next;
            }
        }
        
        if(l1 != NULL)
            tmp->next = l1;
        else
            tmp->next = l2;
        return head;
        
    }
};