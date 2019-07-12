/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
  √ 41/41 cases passed (12 ms)
  √ Your runtime beats 67.2 % of cpp submissions
  √ Your memory usage beats 88.29 % of cpp submissions (9.1 MB)
  √ 41/41 cases passed (8 ms)
  √ Your runtime beats 95.29 % of cpp submissions
  √ Your memory usage beats 76.58 % of cpp submissions (9.2 MB)
*/
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        std::vector<ListNode*> result(k, nullptr);
        if (root == nullptr) { return result; }
        int len = 0;
        for (auto p = root; p != nullptr; p = p->next, ++len);
        int quotient = len / k;
        int remainder = len % k;
        ListNode* partHead = root;
        for (int i = 0; i < k - 1; ++i) {
            result[i] = partHead;
            int partLen = (i < remainder) ? (quotient + 1) : quotient;
            ListNode* p = partHead;
            for (int j = 1; j < partLen; ++j, p = p->next);
            partHead = p->next;
            if (partHead == nullptr) { return result; }
            p->next = nullptr;
        }
        result.back() = partHead;
        return result;
    }
};

