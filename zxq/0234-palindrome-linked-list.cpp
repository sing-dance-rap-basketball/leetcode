/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
  √ 26/26 cases passed (24 ms)
  √ Your runtime beats 76.72 % of cpp submissions
  √ Your memory usage beats 71.61 % of cpp submissions (12.6 MB)
  √ 26/26 cases passed (16 ms)
  √ Your runtime beats 98.7 % of cpp submissions
  √ Your memory usage beats 66.55 % of cpp submissions (12.6 MB)
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        // find start point of second half, then store it in "fast"
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        // reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = fast;
        while (curr != nullptr) {
            ListNode* tempNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempNext;
        }
        // compare first half and reversed second half
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while (p2 != nullptr) {
            if(p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return (p1 == nullptr || p1->next == nullptr);
    }
};

