/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct compare{
    bool operator() (const ListNode* n1, const ListNode* n2) {
        if(n1 && n2) {
            return n1->val > n2->val;
        } else if (n1) {
            return true;
        } else 
            return false;
        
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head = ListNode(-1);
        ListNode  *p = &head;
        std::priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        for(auto l : lists) {
            pq.push(l);
        }
        if(pq.empty()) 
            return head.next;

        do{
            p->next = pq.top();
            pq.pop();
            if(p->next)
                p = p->next;
            if(p->next) 
                pq.push(p->next);
        } while(!pq.empty());
        // ListNode *p = &head;
        // int n = lists.size();
        // while(true) {
        //     int index = -1;
        //     int minval = INT_MAX;
        //     for(int i=0; i<n; i++) {
        //         if(lists[i] && lists[i]->val < minval) {
        //             index = i;
        //             minval = lists[i]->val;
        //         }
        //     }
        //     // std::cout<<index<<endl;
        //     if(index == -1) break;
        //     else {
        //         p->next = lists[index];
        //         lists[index] = lists[index]->next;
        //         p = p->next;
        //     }
        // }
        return head.next;
    }
};

