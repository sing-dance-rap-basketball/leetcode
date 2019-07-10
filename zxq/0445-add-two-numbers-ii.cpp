/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    先反转，再从最低位相加
    √ 1563/1563 cases passed (24 ms)
    √ Your runtime beats 82.59 % of cpp submissions
    √ Your memory usage beats 84.81 % of cpp submissions (10.3 MB)
    √ 1563/1563 cases passed (28 ms)
    √ Your runtime beats 63.16 % of cpp submissions
    √ Your memory usage beats 93.32 % of cpp submissions (10.2 MB)
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr) { return head; }
        ListNode *prev = nullptr, *curr = head;
        while (curr != nullptr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* addTwoNumbersFromLeast(ListNode *l1, ListNode*l2)
    {
        ListNode *node = new ListNode(0);
        ListNode *head = node;
        int carry = 0;
        int l1Val, l2Val;
        
        while (true) {
            l1Val = (l1 != nullptr) ? l1->val : 0;
            l2Val = (l2 != nullptr) ? l2->val : 0;
            node->val = (l1Val + l2Val + carry) % 10;
            carry = (l1Val + l2Val + carry) / 10;
            l1 = (l1 == nullptr) ? nullptr : l1->next;
            l2 = (l2 == nullptr) ? nullptr : l2->next;
            
            if (l1 != nullptr || l2 != nullptr) {
                node->next = new ListNode(0);
                node = node->next;
            }
            else {
                if (carry == 1) {
                    node->next = new ListNode(1);
                    node->next->next = nullptr;
                }
                else { node->next = nullptr; }
                break;
            }
        }
        
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return reverseList(addTwoNumbersFromLeast(
            reverseList(l1), reverseList(l2)
        ));
    }
};

