/**
 * 问题描述
 * 2. Add Two Numbers
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list. 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

/**
 * 提交结果
 * Runtime: 24 ms, faster than 81.10% of C++ online submissions for Add Two Numbers. 
 * Memory Usage: 10.3 MB, less than 61.11% of C++ online submissions for Add Two Numbers.
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
        ListNode *head = new ListNode(0);
        ListNode *current = head;
        int carry = 0;  // 进位
        int sum = 0;    // 当前位的和

        while(true){
            if(l1 != NULL && l2 != NULL){
                sum = l1->val + l2->val + carry;
                current->val = sum % 10;
                carry = sum / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 != NULL && l2 == NULL){
                if(carry == 0){
                    current->val = l1->val;
                    current->next = l1->next;   // 这里有点取巧
                    break;
                }
                else{
                    sum = l1->val + carry;
                    current->val = sum % 10;
                    carry = sum / 10;
                    l1 = l1->next;
                }
            }
            else if(l1 == NULL && l2 != NULL){
                if(carry == 0){
                    current->val = l2->val;
                    current->next = l2->next;
                    break;
                }
                else{
                    sum = l2->val + carry;
                    current->val = sum % 10;
                    carry = sum / 10;
                    l2 = l2->next;
                }
            }

            if(l1 == NULL && l2 == NULL){
                if(carry == 0){
                    current->next = NULL;
                    break;
                }
                else{   // carry == 1
                    current->next = new ListNode(carry);
                    current->next->next = NULL;
                    break;
                }
            }
            else{
                current->next = new ListNode(0);
                current = current->next;
            }
        }

        return head;
    }
};