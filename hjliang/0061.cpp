/**
 * 61. Rotate List
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.
 */

/**
 * Runtime: 8 ms, faster than 83.28% of C++ online submissions for Rotate List.
 * Memory Usage: 8.9 MB, less than 75.00% of C++ online submissions for Rotate List.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0)
            return head;
        
        ListNode *fast = head, *slow = NULL;
        int length = 0;
        while (fast != NULL) {
            fast = fast->next;
            ++length;
            if (length == k)
                break;
        }
        
        if (fast == NULL && length == k)
            return head;
        else if (length < k) {
            fast = head;
            for (int i = 0; i < k % length; ++i)
                fast = fast->next;
        }
        
        slow = head;
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        
        return head;
    }
};