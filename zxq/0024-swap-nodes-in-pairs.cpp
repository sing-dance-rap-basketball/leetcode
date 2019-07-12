/**
 * Description:
 * 24. Swap Nodes in Pairs 
 * Given a linked list, swap every two adjacent nodes and return its head. 
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 */

/**
 * Submissions:
 * Runtime: 4 ms, faster than 82.17% of C++ online submissions for Swap Nodes in Pairs. 
 * Memory Usage: 8.5 MB, less than 81.20% of C++ online submissions for Swap Nodes in Pairs.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { return head; }
        ListNode *l1 = head, *l2 = head->next, *l3 = head->next->next;
        l2->next = l1;
        l1->next = this->swapPairs(l3);
        
        return l2;
    }
};