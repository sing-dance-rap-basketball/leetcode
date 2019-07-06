/**
 * Description: 
 * 
 */

/**
 * Submissions: 
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* begin, ListNode* end)
    {
        if (begin == nullptr) { return nullptr; }
        if (begin->next == end) {   // actually this "if" can be omitted
            TreeNode *root = new TreeNode(begin->val);
            return root;
        }

        ListNode *p = begin;
        ListNode *p_2x = begin;
        while (p_2x != end) {
            p_2x = p_2x->next;
            if (p_2x == end) { break; }
            p_2x = p_2x->next;
            p = p->next;
        }
        TreeNode *root = new TreeNode(p->val);
        root->left = this->sortedListToBST(begin, p);
        root->right = this->sortedListToBST(p->next, end);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, nullptr);
    }
};