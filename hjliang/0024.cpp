/**
 * 24. Swap Nodes in Pairs
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 */

/**
 * Runtime: 4 ms, faster than 80.17% of C++ online submissions for Swap Nodes in Pairs.
 * Memory Usage: 8.5 MB, less than 74.45% of C++ online submissions for Swap Nodes in Pairs.
 * 链表就是个……结构很简单 但是玩着玩着就糊涂了的东西……
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
        ListNode *stackTmp = head;
        ListNode *ret = new ListNode(0);
        ListNode *listTmp = ret;
        
        stack<ListNode *> NodeStack;
        
        while (stackTmp != NULL) {
            if(NodeStack.size() < 2) {
                NodeStack.push(stackTmp);   
            }
            else {
                while (!NodeStack.empty()) {
                    listTmp->next = NodeStack.top();
                    NodeStack.pop();
                    listTmp = listTmp->next;
                    listTmp->next = NULL;
                }  
                continue;
            }
            stackTmp = stackTmp->next;
        }
        
        
        if (stackTmp != NULL)
            listTmp->next = stackTmp;
        
        while (!NodeStack.empty()) {
            listTmp->next = NodeStack.top();
            NodeStack.pop();
            listTmp = listTmp->next;
            listTmp->next = NULL;
        } 
        
        return ret->next;
    }
};