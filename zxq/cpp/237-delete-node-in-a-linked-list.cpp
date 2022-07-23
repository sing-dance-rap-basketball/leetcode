/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
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
  √ 41/41 cases passed (12 ms)
  √ Your runtime beats 87.12 % of cpp submissions
  √ Your memory usage beats 41.74 % of cpp submissions (9.2 MB)
  √ 41/41 cases passed (12 ms)
  √ Your runtime beats 87.12 % of cpp submissions
  √ Your memory usage beats 70.71 % of cpp submissions (9.2 MB)
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node->next->next != nullptr) {
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        node->next = nullptr;
        return;
    }
};

