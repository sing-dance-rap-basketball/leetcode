/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 * 
 *   √ 17/17 cases passed (12 ms)
 *   √ Your runtime beats 82.98 % of cpp submissions
 *   √ Your memory usage beats 46.92 % of cpp submissions (9.8 MB)
 *   √ 17/17 cases passed (8 ms)
 *   √ Your runtime beats 98.45 % of cpp submissions
 *   √ Your memory usage beats 90.04 % of cpp submissions (9.6 MB)
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
    bool hasCycle(ListNode *head) {
        // fast = 2 * slow
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast == nullptr) { return false; }
            fast = fast->next;
            slow = slow->next;
            if (fast == slow) { return true; }
        }

        return false;
    }
};

