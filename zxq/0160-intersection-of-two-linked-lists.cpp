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

// /*
//   √ 45/45 cases passed (56 ms)
//   √ Your runtime beats 33.67 % of cpp submissions
//   √ Your memory usage beats 5.15 % of cpp submissions (20.3 MB)
//   √ 45/45 cases passed (48 ms)
//   √ Your runtime beats 87.36 % of cpp submissions
//   √ Your memory usage beats 5.03 % of cpp submissions (20.5 MB)
// */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if (headA == nullptr || headB == nullptr) {
//             return nullptr;
//         }
//         ListNode* found = nullptr;
//         std::unordered_map<ListNode*, int> ptrInA;
//         for (auto p = headA; p != nullptr; ptrInA[p] = 1, p = p->next);
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
  √ 45/45 cases passed (40 ms)
  √ Your runtime beats 98.52 % of cpp submissions
  √ Your memory usage beats 89.32 % of cpp submissions (16.6 MB)
  √ 45/45 cases passed (48 ms)
  √ Your runtime beats 87.36 % of cpp submissions
  √ Your memory usage beats 41.22 % of cpp submissions (16.8 MB)
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) { return nullptr; }
        int lenA = 0;
        int lenB = 0;
        for (auto p = headA; p; ++lenA, p = p->next);
        for (auto p = headB; p; ++lenB, p = p->next);
        ListNode* pA = headA;
        ListNode* pB = headB;
        if (lenA < lenB) {
            for (int i = 0; i < lenB - lenA; pB = pB->next, ++i);
        }
        else if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; pA = pA->next, ++i);
        }
        while (pA && pB && pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};