/**
 * 2. Add Two Numbers
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *pListNode = new ListNode(0);
        ListNode *head = pListNode;
              
        while(l1 != NULL || l2 != NULL || carry){   
            int x = l1?l1->val:0;
            int y = l2?l2->val:0;
            int sum = x + y + carry;
       
            carry = sum / 10;
            pListNode->next = new ListNode(sum % 10);
            pListNode = pListNode->next;

            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        
		// deal with the first new ListNode(0)
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
        
        return head;
    }
};