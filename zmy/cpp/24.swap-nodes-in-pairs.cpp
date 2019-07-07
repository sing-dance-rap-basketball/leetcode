/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        ListNode **pre = &head, *slow, *fast;
        while((slow=*pre) && (fast = slow->next)) {
            slow->next = fast->next;
            fast->next = slow;
            *pre = fast;
            pre = &(slow->next);
        }
        return head;

        // ListNode x = ListNode(0);
        // x.next = head;
        // ListNode* pre = &x;
        // while(pre && pre->next && pre->next->next) {
        //     ListNode* fast = pre;
        //     ListNode* slow = pre;
        //     slow = slow->next;
        //     fast = fast->next;
        //     if(fast->next)
        //         fast = fast->next;
        //     slow->next = fast->next;
        //     fast->next = slow;
        //     pre->next = fast;
        //     pre=pre->next->next;
        // }
        // return x.next;
    }
};

