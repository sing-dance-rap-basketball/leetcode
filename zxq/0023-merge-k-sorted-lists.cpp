/**
 * 问题：
 * 23. Merge k Sorted Lists
 * Merge k sorted linked lists and return it as one sorted list. 
 * Analyze and describe its complexity.
 */

/**
 * 运行结果：
 * Runtime: 332 ms, faster than 12.75% of C++ online submissions for Merge k Sorted Lists. 
 * Memory Usage: 10.9 MB, less than 79.11% of C++ online submissions for Merge k Sorted Lists.
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
        auto it = lists.begin();
        while (it != lists.end()) {
            if (*it == nullptr) { 
                if (it == lists.end() - 1) {
                    lists.erase(it);
                    break;
                }
                else {
                    lists.erase(it);
                    continue;
                }
            }
            ++it;
        }
        if (lists.size() == 0) { return nullptr; }
        if (lists.size() == 1) { return lists[0]; }
        
        vector<ListNode*> heads{ lists[0] };    //sorted heads
        for (int i = 1; i < lists.size(); ++i) {
            // binary search is better
            bool isInserted = false;
            for (auto it = heads.begin(); it != heads.end(); ++it) {
                //if (lists[i] == nullptr) { break; }
                if ((*it)->val >= lists[i]->val) {
                    heads.insert(it, lists[i]);
                    isInserted = true;
                    break;
                } 
            }
            if (!isInserted) { heads.insert(heads.end(), lists[i]); }
        }
        
        ListNode* pseudoHead = new ListNode(-1);
        ListNode* l = pseudoHead;
        while (!heads.empty()) {
            l->next = heads.at(0);
            l = l->next;
            ListNode* newHead = l->next;
            if (newHead == nullptr) {
                heads.erase(heads.begin());
                if (heads.size() == 1) {
                    l->next = heads[0];
                    break;
                }
            }
            else {
                heads.erase(heads.begin());
                bool isInserted = false;
                for (auto it = heads.begin(); it != heads.end(); ++it) {
                    if((*it)->val >= newHead->val) {
                        heads.insert(it, newHead);
                        isInserted = true;
                        break;
                    }
                }
                if (!isInserted) { heads.insert(heads.end(), newHead); }
            }
        }
        
        return pseudoHead->next;
    }
};