/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
 * 
 * Given a binary search tree, rearrange the tree in in-order 
 * so that the leftmost node in the tree is now the root of the 
 * tree, and every node has no left child and only 1 right child.
 */

// @lc code=start

/**
 * Accepted
    35/35 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (7.1 MB)
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        dummy->right = root;
        TreeNode* node = dummy;
        while (node->right != nullptr) {
            if (node->right->left == nullptr) {
                node = node->right;
            }
            else {
                auto temp = node->right;
                node->right = node->right->left;
                temp->left = nullptr;

                auto ptr = node->right; 
                while (ptr->right != nullptr) {
                    ptr = ptr->right;
                }
                ptr->right = temp;
            }
        }
        return dummy->right;
    }
};
// @lc code=end

