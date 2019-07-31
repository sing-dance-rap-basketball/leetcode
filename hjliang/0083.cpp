/**
 * 83. Remove Duplicates from Sorted List
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 */


/**
 * Runtime: 12 ms, faster than 76.17% of C++ online submissions for Remove Duplicates from Sorted List.
 * Memory Usage: 9.2 MB, less than 74.34% of C++ online submissions for Remove Duplicates from Sorted List.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode *pList = head;
        while (pList->next != NULL) {
            if (pList->val == (pList->next)->val)
                pList->next = (pList->next)->next;
            else
                pList = pList->next;
        }
        return head;
    }
};