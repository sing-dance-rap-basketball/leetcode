/**
 * 问题：
 * 21. Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.
 */

/**
 * 运行结果：
 * Runtime: 8 ms, faster than 86.93% of C++ online submissions for Merge Two Sorted Lists. 
 * Memory Usage: 8.8 MB, less than 82.60% of C++ online submissions for Merge Two Sorted Lists.
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
        if (l1 == nullptr) { return l2; }
        if (l2 == nullptr) { return l1; }
        
        ListNode* newList = new ListNode(0);
        ListNode* l = newList;
        
        while (true) {
            if (l1->val <= l2->val) {
                l->next = l1;
                l1 = l1->next;
            }
            else {
                l->next = l2;
                l2 = l2->next;
            }
            l = l->next;
            
            if (l1 == nullptr) {
                l->next = l2;
                break;
            }
            if (l2 == nullptr) {
                l->next = l1;
                break;
            }
        }
        
        newList = newList->next;
        return newList;
    }
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) { return l2; }
    if (l2 == nullptr) { return l1; }
    
    ListNode* pseudoHead = new ListNode(-1);
    ListNode* l = pseudoHead;
    
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            l->next = l1;
            l1 = l1->next;
        }
        else {
            l->next = l2;
            l2 = l2->next;
        }
        l = l->next;
    }
    l->next = (l1 == nullptr) ? l2 : l1;
    
    return pseudoHead->next;
}