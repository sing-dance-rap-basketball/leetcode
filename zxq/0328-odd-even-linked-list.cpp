/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
  √ 71/71 cases passed (16 ms)
  √ Your runtime beats 80.11 % of cpp submissions
  √ Your memory usage beats 25.7 % of cpp submissions (9.7 MB)
  √ 71/71 cases passed (12 ms)
  √ Your runtime beats 98.74 % of cpp submissions
  √ Your memory usage beats 86.67 % of cpp submissions (9.5 MB)
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        ListNode *l = head;
        ListNode *evenHead = head->next, *evenTail = nullptr;
        while (l->next && l->next->next) {
            if (evenTail == nullptr) {
                evenTail = l->next; // head->next
            }
            else {
                evenTail->next = l->next;
                evenTail = l->next;
            }
            l->next = l->next->next;
            l = l->next;
        }
        if (l->next == nullptr) {
            l->next = evenHead;
            evenTail->next = nullptr;
        }
        else {  // that is, l->next->next == nullptr
            evenTail->next = l->next;
            l->next = evenHead;
        }
        return head;
    }
};

