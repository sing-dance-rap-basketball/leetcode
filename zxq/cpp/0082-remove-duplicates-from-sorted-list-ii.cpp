/**
 * Description: 
 * 82. Remove Duplicates from Sorted List II
 * Given a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list.
 */

/**
 * Submissions: 
 * Runtime: 8 ms, faster than 90.44% of C++ online submissions for Remove Duplicates from Sorted List II. 
 * Memory Usage: 9.2 MB, less than 35.32% of C++ online submissions for Remove Duplicates from Sorted List II.
 * Runtime: 12 ms, faster than 33.90% of C++ online submissions for Remove Duplicates from Sorted List II. 
 * Memory Usage: 9.1 MB, less than 43.32% of C++ online submissions for Remove Duplicates from Sorted List II.
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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *pseudoHead = new ListNode(-1);
        pseudoHead->next = head;
        ListNode *o = pseudoHead;
        ListNode *p = head;
        ListNode *q = head->next;
        while (q != nullptr) {
            if (p->val != q->val) {
                o = p;
                p = q;
                q = q->next;
            }
            else {
                q = q->next;
                p->next = q;
                if (q == nullptr) {
                    o->next = nullptr;
                    break;
                }
                if (p->val != q->val) {
                    p = q;
                    q = q->next;
                    o->next = p;
                }
            }
        }
        
        return pseudoHead->next;
    }
};