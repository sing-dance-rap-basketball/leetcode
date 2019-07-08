/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// /*  
//     √ 16/16 cases passed (20 ms)
//     √ Your runtime beats 27.36 % of cpp submissions
//     √ Your memory usage beats 5.01 % of cpp submissions (12.5 MB)
//     √ 16/16 cases passed (16 ms) 
//     √ Your runtime beats 33.9 % of cpp submissions 
//     √ Your memory usage beats 5.01 % of cpp submissions (12.4 MB)
//     √ 16/16 cases passed (12 ms)
//     √ Your runtime beats 84.34 % of cpp submissions
//     √ Your memory usage beats 5.01 % of cpp submissions (12.4 MB) 
// */
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         if (head == nullptr) { return nullptr; }
//         std::unordered_map<ListNode *, int> umap;
//         ListNode *node = head;
//         int pos = 0;
//         while (node != nullptr) {
//             auto got = umap.find(node);
//             if (got != umap.end()) {
//                 return got->first;
//             }
//             umap[node] = pos;
//             node = node->next;
//             ++pos;
//         }
//         return nullptr;
//     }
// };

/**
 * Follow-up:
 * Can you solve it without using extra space?
 */
/*
  √ 16/16 cases passed (8 ms)
  √ Your runtime beats 98.66 % of cpp submissions
  √ Your memory usage beats 47.61 % of cpp submissions (9.8 MB)
  √ 16/16 cases passed (12 ms)
  √ Your runtime beats 84.34 % of cpp submissions
  √ Your memory usage beats 95.27 % of cpp submissions (9.6 MB)
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool flag = false;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { // meeting point
                flag = true;
                break;
            }
        }
        if (!flag) { return nullptr; }
        ListNode *result = head;
        while (result != slow) {
            result = result->next;
            slow = slow->next;
        }
        return result;
    }
};