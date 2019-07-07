/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if ( !head || !(head->next) || k<2 ) 
            return head;
        ListNode xx(-1);
        xx.next = head;
        ListNode *begin = &xx;
        ListNode *end = &xx;
        while ( true ) {
            for ( int i = 0; i < k && end; ++i )
                end = end->next;
            if (end == nullptr) 
                break;
            ListNode *curr = begin->next;
            for ( int i = 0; i < k-1; ++i ) {
                ListNode *tmp = curr->next;
                curr->next = tmp->next;
                tmp->next = begin->next;
                begin->next = tmp;
            }
            begin = curr;
            end = curr;
        }
        return xx.next;
    }
};

