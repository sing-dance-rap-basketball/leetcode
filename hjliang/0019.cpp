/**
 * 19. Remove Nth Node From End of List
 * Given a linked list, remove the n-th node from the end of list and return its head.
 * Note: 
 * 		Given n will always be valid.
 *		Could you do this in one pass?
 */

/**
 * Runtime: 4 ms, faster than 91.32% of C++ online submissions for Remove Nth Node From End of List.
 * Memory Usage: 8.7 MB, less than 5.17% of C++ online submissions for Remove Nth Node From End of List.
 * 
 * 删除节点是不是要释放内存
 * 队列的想法应该是对的 但特殊情况如何优雅的处理掉
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> ListQueue;
        ListNode *tmp = head;
        if(tmp->next == NULL && n == 1)
            return NULL;
        while (tmp->next != NULL) {
            ListQueue.push(tmp);
            if(ListQueue.size() > n)
                ListQueue.pop();
            tmp = tmp->next;
        }
        ListQueue.push(tmp);
        if(ListQueue.size() == n)
            return ListQueue.front()->next;
        ListNode *frontDel = ListQueue.front();
        ListQueue.pop();
        ListQueue.pop();
        frontDel->next = ListQueue.size() == 0?NULL:ListQueue.front();
        return head;
    }
};