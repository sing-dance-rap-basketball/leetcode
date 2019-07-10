/**
 * 23. Merge k Sorted Lists
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

/**
 * Runtime: 404 ms, faster than 8.46% of C++ online submissions for Merge k Sorted Lists.
 * Memory Usage: 10.8 MB, less than 87.10% of C++ online submissions for Merge k Sorted Lists.
 * 思路参考21题 知不道为啥那么慢…… 虽然有一些多余的操作
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int num = lists.size();
        ListNode *head = new ListNode(0);
        ListNode *tmp = head;
        while (true) {
            int min = INT_MAX, minIndex = -1;
            for (int i = 0; i < num; ++i) {
                if (lists[i] == NULL) 
                    continue;
                if (lists[i]->val < min) {
                    min = lists[i]->val;
                    minIndex = i;
                }
            }
            if(minIndex == -1)
                break;
            
            tmp->next = lists[minIndex];
            lists[minIndex] = lists[minIndex]->next;
            tmp = tmp->next;
        }
        return head->next;
    }
};