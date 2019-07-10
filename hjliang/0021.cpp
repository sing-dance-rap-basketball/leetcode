/**
 * 21. Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */

/**
 * Runtime: 8 ms, faster than 85.83% of C++ online submissions for Merge Two Sorted Lists.
 * Memory Usage: 8.9 MB, less than 51.70% of C++ online submissions for Merge Two Sorted Lists.
 * 整合了之前多余的部分
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
        ListNode head(0);
        ListNode *tmp = &head;
        
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
        
        if (l1 != NULL)
            tmp->next = l1;
        if (l2 != NULL)
            tmp->next = l2;
        
        return head.next;
    }
};