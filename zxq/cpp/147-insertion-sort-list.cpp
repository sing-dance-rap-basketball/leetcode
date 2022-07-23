/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
  √ 22/22 cases passed (48 ms)
  √ Your runtime beats 72.41 % of cpp submissions
  √ Your memory usage beats 48.28 % of cpp submissions (9.6 MB)
  √ 22/22 cases passed (48 ms)
  √ Your runtime beats 72.41 % of cpp submissions
  √ Your memory usage beats 24.56 % of cpp submissions (9.6 MB)
*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *unsorted = head->next;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        head->next = nullptr;
        while (unsorted != nullptr) {
            ListNode *temp = unsorted;
            unsorted = unsorted->next;
            ListNode *p = dummy;
            for (; p->next != nullptr && temp->val > p->next->val; p = p->next);
            temp->next = p->next;
            p->next = temp;
        }
        return dummy->next;
    }
};