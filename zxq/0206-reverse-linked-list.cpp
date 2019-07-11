/**
 * Description: 
 * 206. Reverse Linked List
 * Reverse a singly linked list.
 * Follow up: 
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

/**
 * "Iteratively" version
 * Submissions: 
 * Runtime: 4 ms, faster than 99.43% of C++ online submissions for Reverse Linked List. 
 * Memory Usage: 9.2 MB, less than 30.48% of C++ online submissions for Reverse Linked List.
 * Runtime: 16 ms, faster than 13.56% of C++ online submissions for Reverse Linked List. 
 * Memory Usage: 9.1 MB, less than 81.16% of C++ online submissions for Reverse Linked List.
 * Runtime: 8 ms, faster than 87.14% of C++ online submissions for Reverse Linked List. 
 * Memory Usage: 9.1 MB, less than 79.69% of C++ online submissions for Reverse Linked List.
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) { return head; }
        
        ListNode *temp = head;
        head = head->next;
        temp->next = nullptr;
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            temp->next = dummyHead->next;
            dummyHead->next = temp;
        }
        
        return dummyHead->next;
    }
};

/**
 * "Recursively" version
 * Submissions: 
 * Runtime: 4 ms, faster than 99.43% of C++ online submissions for Reverse Linked List. 
 * Memory Usage: 9.4 MB, less than 5.08% of C++ online submissions for Reverse Linked List. 
 * Runtime: 8 ms, faster than 87.14% of C++ online submissions for Reverse Linked List. 
 * Memory Usage: 9.3 MB, less than 18.47% of C++ online submissions for Reverse Linked List.
 */

ListNode* reverseList(ListNode* head) {
    if (head == nullptr) { return head; }
    
    ListNode *second = head->next;
    if (second == nullptr) { return head; }
    ListNode *newHead = this->reverseList(second);
    second->next = head;
    head->next = nullptr;
    
    return newHead;        
}