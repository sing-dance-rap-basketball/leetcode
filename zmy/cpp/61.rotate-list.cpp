/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || !k ) return head;

        ListNode* p = head;
        int len = 1;
        while(p->next) {
            p = p->next;
            len++;
        }

        p->next = head;
        k = k%len;
        while(--len >= k) {
            p = p->next;
        }
        ListNode * nh = p->next;
        p->next = nullptr;
        return nh;

    }
};

