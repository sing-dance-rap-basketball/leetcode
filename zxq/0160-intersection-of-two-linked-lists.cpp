/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
//   √ 45/45 cases passed (56 ms)
//   √ Your runtime beats 33.67 % of cpp submissions
//   √ Your memory usage beats 9.08 % of cpp submissions (20 MB)
//   √ 45/45 cases passed (72 ms)
//   √ Your runtime beats 12.77 % of cpp submissions
//   √ Your memory usage beats 8.73 % of cpp submissions (20 MB)
//   √ 45/45 cases passed (64 ms)
//   √ Your runtime beats 24.64 % of cpp submissions
//   √ Your memory usage beats 8.16 % of cpp submissions (20.1 MB)
// */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if (headA == nullptr || headB == nullptr) {
//             return nullptr;
//         }
//         ListNode* found = nullptr;
//         std::set<ListNode*> ptrInA;
//         for (auto p = headA; p != nullptr; ptrInA.insert(p), p = p->next);
//         for (auto p = headB; p != nullptr; p = p->next) {
//             if (ptrInA.find(p) != ptrInA.end()) {
//                 found = p;
//                 break;
//             }
//         }
//         return found;
//     }
// };

/*
  √ 45/45 cases passed (56 ms)
  √ Your runtime beats 33.67 % of cpp submissions
  √ Your memory usage beats 5.15 % of cpp submissions (20.3 MB)
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode* found = nullptr;
        std::unordered_map<ListNode*, int> ptrInA;
        for (auto p = headA; p != nullptr; ptrInA[p] = 1, p = p->next);
        for (auto p = headB; p != nullptr; p = p->next) {
            if (ptrInA.find(p) != ptrInA.end()) {
                found = p;
                break;
            }
        }
        return found;
    }
};