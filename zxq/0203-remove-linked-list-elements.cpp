/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
  √ 65/65 cases passed (24 ms)
  √ Your runtime beats 96.53 % of cpp submissions
  √ Your memory usage beats 44.77 % of cpp submissions (11 MB)
  √ 65/65 cases passed (28 ms)
  √ Your runtime beats 76.9 % of cpp submissions
  √ Your memory usage beats 95.28 % of cpp submissions (10.8 MB)
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        for (auto p = dummy; p->next != nullptr; ) {
            if (p->next->val == val) {
                p->next = p->next->next;
            }
            else {
                p = p->next;
            }
        }
        return dummy->next;
    }
};

