/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
//   √ 13/13 cases passed (48 ms)
//   √ Your runtime beats 84.46 % of cpp submissions
//   √ Your memory usage beats 13.09 % of cpp submissions (13.2 MB)
//   √ 13/13 cases passed (48 ms)
//   √ Your runtime beats 84.46 % of cpp submissions
//   √ Your memory usage beats 10.07 % of cpp submissions (13.3 MB)
//   √ 13/13 cases passed (48 ms)
//   √ Your runtime beats 84.46 % of cpp submissions
//   √ Your memory usage beats 15.06 % of cpp submissions (13.1 MB)
// */
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         if (head == nullptr) { return; }
//         std::vector<ListNode *> list;
//         while (head != nullptr) {
//             list.push_back(head);
//             head = head->next;
//         }
//         head = list[0]; // important
//         ListNode *dummyHead = new ListNode(-1);
//         list.push_back(dummyHead);
//         int front = 0;
//         int rear = list.size() - 1;
//         while (front < rear) {
//             list[rear]->next = list[front];
//             --rear;
//             if (front == rear) { break; }
//             list[front]->next = list[rear];
//             ++front;
//         }
//         list[rear]->next = nullptr;
//         return;
//     }
// };

/*
    solution from xiabofei
    Step1. get the mid Node of the list
    Step2. reverse the second half list
    Step3. merge the two half lists
    Clean & Concise is better

    √ 13/13 cases passed (48 ms)
    √ Your runtime beats 84.46 % of cpp submissions
    √ Your memory usage beats 83.14 % of cpp submissions (12 MB) 
    √ 13/13 cases passed (40 ms)
    √ Your runtime beats 99.77 % of cpp submissions
    √ Your memory usage beats 87.95 % of cpp submissions (12 MB)
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) { return; }
        if (head->next == nullptr) { return; }
        // find point next to the mid
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr) { break; }
            fast = fast->next;
        }
        // the second half begins with "slow", reverse it
        ListNode *curr = slow, *prev = nullptr, *tempNext;
        while (curr != nullptr) {
            tempNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempNext;
        }
        // merge the two halves
        ListNode *l1 = head, *l2 = prev;
        while (l2->next != nullptr) {
            tempNext = l2->next;
            l2->next = l1->next;
            l1->next = l2;
            l1 = l2->next;
            l2 = tempNext;
        }
        if (l1->next == slow) {
            l1->next = l2;
            l2->next = nullptr;
        }
        else {
            l2->next = l1->next;
            l1->next = l2;
            l2->next->next = nullptr;
        }
        return;
    }
};