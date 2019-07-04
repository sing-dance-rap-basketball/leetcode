/**
 * 问题描述
 * 19. Remove Nth Node From End of List
 * Given a linked list, remove the n-th node from the end of list and return its head.
 * Note: Given n will always be valid.
 * Follow up: Could you do this in one pass?
 */

/**
 * 提交结果
 * Runtime: 4 ms, faster than 92.36% of C++ online submissions for Remove Nth Node From End of List. 
 * Memory Usage: 8.6 MB, less than 24.03% of C++ online submissions for Remove Nth Node From End of List.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* nextNode = head;
        
        while (nextNode != NULL) {
            nextNode = nextNode->next;
            ++len;
        }
        
        if (n == len) {
            head = head->next;
            return head;
        }
        else {
            nextNode = head;
            for (int i = 0; i < len - n - 1; ++i) {
                nextNode = nextNode->next;
            }
            nextNode->next = nextNode->next->next;
            return head;
        }
    }
}

/**
 * 提交结果：
 * Runtime: 4 ms, faster than 92.10% of C++ online submissions for Remove Nth Node From End of List.
 * Memory Usage: 8.4 MB, less than 87.12% of C++ online submissions for Remove Nth Node From End of List.
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* firstNode = head;
    ListNode* secondNode = head;
    
    for (int i = 0; i <= n; ++i) {
        if (secondNode == nullptr) {
            return head->next;
        }
        secondNode = secondNode->next;
    }
    
    while (secondNode != nullptr) {
        firstNode = firstNode->next;
        secondNode = secondNode->next;
    }
    firstNode->next = firstNode->next->next;
    
    return head;
}