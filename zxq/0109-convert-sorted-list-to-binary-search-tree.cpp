/**
 * Description: 
 * 109. Convert Sorted List to Binary Search Tree
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 * For this problem, a height-balanced binary tree is defined as a binary tree 
 * in which the depth of the two subtrees of every node never differ by more than 1.
 */

/**
 * Submissions: 
 * Runtime: 32 ms, faster than 67.49% of C++ online submissions for Convert Sorted List to Binary Search Tree. 
 * Memory Usage: 24.5 MB, less than 51.05% of C++ online submissions for Convert Sorted List to Binary Search Tree. 
 * Runtime: 20 ms, faster than 99.56% of C++ online submissions for Convert Sorted List to Binary Search Tree. 
 * Memory Usage: 24.5 MB, less than 46.84% of C++ online submissions for Convert Sorted List to Binary Search Tree. 
 * Runtime: 36 ms, faster than 42.87% of C++ online submissions for Convert Sorted List to Binary Search Tree. 
 * Memory Usage: 24.6 MB, less than 30.14% of C++ online submissions for Convert Sorted List to Binary Search Tree.
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
        if (begin == end) { return nullptr; }
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

class Solution {
public:
    void createBST(TreeNode **root, ListNode *begin, ListNode *end)
    {
        if (begin == end) { 
            *root = nullptr;
            return;
        }
        if (begin->next == end) {
            (*root)->val = begin->val;
            (*root)->left = nullptr;
            (*root)->right = nullptr;
            return;
        }

        ListNode *p = begin;
        ListNode *p_2x = begin;
        while (p_2x != end) {
            p_2x = p_2x->next;
            if (p_2x == end) { break; }
            p_2x = p_2x->next;
            p = p->next;
        }
        (*root)->val = p->val;
        (*root)->left = new TreeNode(0);
        (*root)->right = new TreeNode(0);
        createBST(&((*root)->left), begin, p);
        createBST(&((*root)->right), p->next, end);

        return;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode *root = new TreeNode(0);
        createBST(&root, head, nullptr);
        return root;
    }
};