
/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p = new ListNode(0);
		ListNode *q = p;
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		// while(p1->next!=NULL)
		// p1=p1->next;
		//  while(p2->next!=NULL)
		//p2=p2->next;
		//int flag=0;
		int flag = 0;
		while (p1 != NULL || p2 != NULL)
		{
			if (p1 != NULL&&p2 != NULL)
			{
				p->val = p1->val + p2->val + flag;
				if (p->val >= 10)
				{
					p->val = p->val - 10;
					flag = 1;
				}
				else
					flag = 0;
				p1 = p1->next;
				p2 = p2->next;
				ListNode *p3 = new ListNode(0);
				p->next = p3;
				p = p3;
			}
			else
			if (p1 == NULL)
			{
				p->val = p2->val + flag;
				if (p->val >= 10)
				{
					p->val = p->val - 10;
					flag = 1;
				}
				else
					flag = 0;
				//p1 = p1->next;
				p2 = p2->next;
				ListNode *p3 = new ListNode(0);
				p->next = p3;
				p = p3;
			}
			else
			if (p2 == NULL)
			{
				p->val = p1->val + flag;
				if (p->val >= 10)
				{
					p->val = p->val - 10;
					flag = 1;
				}
				else
					flag = 0;
				p1 = p1->next;
				//p2 = p2->next;
				ListNode *p3 = new ListNode(0);
				p->next = p3;
				p = p3;
			}
		}
        if (flag == 1)
			p->val = 1;
       p = q;
		while (p->next != NULL)
		{
			if (!(p->next->next == NULL&&p->next->val == 0))
				p = p->next;
			else
			{
				p->next = NULL;
				break;
			}
		}
		return q;
		
	}

};
