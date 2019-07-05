/**
 * Description:
 * 25. Reverse Nodes in k-Group
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list. 
 * k is a positive integer and is less than or equal to the length of the linked list. 
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * Note: 
 * Only constant extra memory is allowed. 
 * You may not alter the values in the list's nodes, only nodes itself may be changed.
 */

/**
 * Submission:
 * Runtime: 12 ms, faster than 99.96% of C++ online submissions for Reverse Nodes in k-Group. 
 * Memory Usage: 11.3 MB, less than 5.01% of C++ online submissions for Reverse Nodes in k-Group.
 * Runtime: 20 ms, faster than 84.30% of C++ online submissions for Reverse Nodes in k-Group. 
 * Memory Usage: 11.3 MB, less than 5.01% of C++ online submissions for Reverse Nodes in k-Group.
 * Runtime: 28 ms, faster than 17.28% of C++ online submissions for Reverse Nodes in k-Group. 
 * Memory Usage: 11.2 MB, less than 5.01% of C++ online submissions for Reverse Nodes in k-Group.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) { return head; }
        
        std::vector<ListNode*> temp{ head };
        ListNode *l = head;
        for (int i = 1; i < k; ++i) {
            l = l->next;
            if (l == nullptr) { return head; }
            temp.push_back(l);
        }
        l = l->next;
        
        ListNode *pseudoHead = new ListNode(-1);
        ListNode *p = pseudoHead;
        for (int i = k-1; i >= 0; --i) {
            p->next = temp[i];
            p = p->next;
        }
        temp.clear();
        temp.shrink_to_fit();
        
        p->next = this->reverseKGroup(l, k);
        return pseudoHead->next;
    }
};