/**
 * 25. Reverse Nodes in k-Group
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 */

/**
 * Runtime: 20 ms, faster than 81.85% of C++ online submissions for Reverse Nodes in k-Group.
 * Memory Usage: 10.1 MB, less than 6.25% of C++ online submissions for Reverse Nodes in k-Group.
 * 因为24题就用了栈 于是在24的基础上小改了下…… 
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
        ListNode *stackTmp = head;
        ListNode *ret = new ListNode(0);
        ListNode *listTmp = ret;
        
        stack<ListNode *> NodeStack;
        
        while (stackTmp != NULL) {
            if(NodeStack.size() < k) {
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
        
        if (NodeStack.size() < k && NodeStack.size() != 0) {
            while (NodeStack.size() > 1) 
                NodeStack.pop();
            listTmp->next = NodeStack.top();
            NodeStack.pop();
        }
        
        while (!NodeStack.empty()) {
            listTmp->next = NodeStack.top();
            NodeStack.pop();
            listTmp = listTmp->next;
            listTmp->next = NULL;
        } 
        
        return ret->next;    
    }
};