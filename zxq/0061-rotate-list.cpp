/**
 * Description: 
 * 61. Rotate List
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.
 */

/**
 * Submissions: 
 * Runtime: 4 ms, faster than 99.10% of C++ online submissions for Rotate List. 
 * Memory Usage: 9.1 MB, less than 5.19% of C++ online submissions for Rotate List.
 * Runtime: 8 ms, faster than 88.17% of C++ online submissions for Rotate List. 
 * Memory Usage: 9.3 MB, less than 5.05% of C++ online submissions for Rotate List.
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
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head; 
        }
        
        std::vector<ListNode *> vec{ head };
        while (vec.back()->next) {
            vec.push_back(vec.back()->next);
        }
        int len = vec.size();
        
        int remainder = k % len;
        ListNode *newHead = head;
        if (remainder != 0) {
            newHead = vec[len - remainder];
            vec.back()->next = vec.front();
            vec[len - remainder -1]->next = nullptr;
        }
        
        std::vector<ListNode *>().swap(vec);
        return newHead;
    }
};