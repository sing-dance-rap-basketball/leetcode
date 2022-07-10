/**
 * Description: 
 * 83. Remove Duplicates from Sorted List
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 */

/**
 * Submissions: 
 * Runtime: 12 ms, faster than 83.69% of C++ online submissions for Remove Duplicates from Sorted List. 
 * Memory Usage: 9.2 MB, less than 71.77% of C++ online submissions for Remove Duplicates from Sorted List.
 * Runtime: 8 ms, faster than 98.56% of C++ online submissions for Remove Duplicates from Sorted List. 
 * Memory Usage: 9.2 MB, less than 53.00% of C++ online submissions for Remove Duplicates from Sorted List.
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
        if (head == nullptr) {
            return head;
        }
        
        ListNode *p = head;
        ListNode *q = head->next;
        while (q != nullptr) {
            if (p->val == q->val) {
                q = q->next;
                p->next = q;
            }
            else {
                p = q;
                q = q->next;
            }
        }
        
        return head;
    }
}; 