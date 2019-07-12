/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
//   √ 16/16 cases passed (56 ms)
//   √ Your runtime beats 45.91 % of cpp submissions
//   √ Your memory usage beats 18.52 % of cpp submissions (24.9 MB)
//   √ 16/16 cases passed (48 ms)
//   √ Your runtime beats 62.64 % of cpp submissions
//   √ Your memory usage beats 26.14 % of cpp submissions (24.7 MB)
// */
// class Solution {
// public:
//     ListNode* merge(ListNode* l1, ListNode* l2) 
//     {
//         if (l1 == nullptr) { return l2; }
//         if (l2 == nullptr) { return l1; }
        
//         ListNode* dummy = new ListNode(-1);
//         ListNode* l = dummy;
        
//         while (l1 && l2) {
//             if (l1->val <= l2->val) {
//                 l->next = l1;
//                 l1 = l1->next;
//             }
//             else {
//                 l->next = l2;
//                 l2 = l2->next;
//             }
//             l = l->next;
//         }
//         l->next = (l1 == nullptr) ? l2 : l1;
        
//         return dummy->next;
//     }

//     ListNode* mergeSort(ListNode* head, ListNode* tail)
//     {
//         if (head == tail) { return nullptr; }
//         if (head->next == tail) {
//             head->next = nullptr;
//             return head;
//         }
//         ListNode *slow = head;
//         ListNode *fast = head;
//         while (fast != tail) {
//             if (fast->next == tail) { break; }
//             fast = fast->next->next;
//             slow = slow->next;
//         }
//         return merge(mergeSort(head, slow), mergeSort(slow, tail));
//     }

//     ListNode* sortList(ListNode* head) {
//         return mergeSort(head, nullptr);
//     }
// };

// /*
//   √ 16/16 cases passed (56 ms)
//   √ Your runtime beats 45.2 % of cpp submissions
//   √ Your memory usage beats 23.83 % of cpp submissions (24.8 MB)
// */
// class Solution {
// public:
//     ListNode* merge(ListNode* l1, ListNode* l2) 
//     {        
//         ListNode* dummy = new ListNode(-1);
//         ListNode* l = dummy;
        
//         while (l1 && l2) {
//             if (l1->val <= l2->val) {
//                 l->next = l1;
//                 l1 = l1->next;
//             }
//             else {
//                 l->next = l2;
//                 l2 = l2->next;
//             }
//             l = l->next;
//         }
//         l->next = (l1 == nullptr) ? l2 : l1;
        
//         return dummy->next;
//     }

//     ListNode* sortList(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) {
//             return head;
//         }
//         ListNode* slow = head;
//         ListNode* fast = head->next;
//         while (fast != nullptr && fast->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         fast = slow->next;
//         slow->next = nullptr;
//         return merge(sortList(head), sortList(fast));
//     }
// };

/*
  √ 16/16 cases passed (40 ms)
  √ Your runtime beats 97.95 % of cpp submissions
  √ Your memory usage beats 60.92 % of cpp submissions (11.9 MB)
  √ 16/16 cases passed (40 ms)
  √ Your runtime beats 97.95 % of cpp submissions
  √ Your memory usage beats 83.72 % of cpp submissions (11.6 MB)
*/
class Solution {
public:
    ListNode* dummy;
    ListNode* l;

    ListNode* merge(ListNode* l1, ListNode* l2) 
    {
        l = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                l->next = l1;
                l1 = l1->next;
            }
            else {
                l->next = l2;
                l2 = l2->next;
            }
            l = l->next;
        }
        l->next = (l1 == nullptr) ? l2 : l1;
        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return merge(mergeSort(head), mergeSort(fast));
    }

    ListNode* sortList(ListNode* head) {
        dummy = new ListNode(-1);
        return mergeSort(head);
    }
};