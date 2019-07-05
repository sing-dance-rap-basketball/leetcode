/**
 * Description: 
 * 92. Reverse Linked List II
 * Reverse a linked list from position m to n. Do it in one-pass. 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 */

/**
 * Submissions: 
 * Runtime: 4 ms, faster than 80.51% of C++ online submissions for Reverse Linked List II. 
 * Memory Usage: 8.5 MB, less than 87.78% of C++ online submissions for Reverse Linked List II. 
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Linked List II. 
 * Memory Usage: 8.6 MB, less than 67.43% of C++ online submissions for Reverse Linked List II. 
 * Runtime: 4 ms, faster than 80.51% of C++ online submissions for Reverse Linked List II. 
 * Memory Usage: 8.6 MB, less than 47.08% of C++ online submissions for Reverse Linked List II.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr) { return nullptr; }
        
        ListNode *prev = (m == 1) ? nullptr : head;
        for (int i = 1; i < m - 1; ++i) {
            prev = prev->next;
        }
        ListNode *prevTemp = prev;
        ListNode *curr = (m == 1) ? head : prev->next;
        ListNode *tail = curr;
        for (int i = m; i <= n; ++i) {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        tail->next = curr;
        if (prevTemp == nullptr) {
            return prev;
        }
        else {
            prevTemp->next = prev;
            return head;
        }
    }
};