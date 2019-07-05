/**
 * Description: 
 * 86. Partition List
 * Given a linked list and a value x, partition it 
 * such that all nodes less than x come before nodes greater than or equal to x. 
 * You should preserve the original relative order of the nodes in each of the two partitions.
 */

/**
 * Submissions: 
 * Runtime: 8 ms, faster than 75.21% of C++ online submissions for Partition List. 
 * Memory Usage: 8.8 MB, less than 14.99% of C++ online submissions for Partition List.
 * Runtime: 4 ms, faster than 98.28% of C++ online submissions for Partition List. 
 * Memory Usage: 8.7 MB, less than 49.15% of C++ online submissions for Partition List.
 * Runtime: 4 ms, faster than 98.28% of C++ online submissions for Partition List. 
 * Memory Usage: 8.6 MB, less than 82.54% of C++ online submissions for Partition List.
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *l1 = dummyHead;
        ListNode *head2 = new ListNode(0);
        ListNode *l2 = head2;
        while (l1->next != nullptr) {
            if (l1->next->val >= x) {
                l2->next = l1->next;
                l1->next = l1->next->next;
                l2 = l2->next;
            }
            else {
                l1 = l1->next;
            }
        }
        
        if (dummyHead->next == nullptr) {
            return head2->next;
        }
        else {
            l2->next = nullptr;
            l1->next = head2->next;
            return dummyHead->next;
        }
    }
};