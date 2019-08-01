/**
 * Given two binary trees, write a function to check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
 */
 
 /**
 * Runtime: 4 ms, faster than 62.70% of C++ online submissions for Same Tree.
 * Memory Usage: 9.7 MB, less than 79.61% of C++ online submissions for Same Tree.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compareTree(p,q);
    }
    
    bool compareTree(TreeNode *p, TreeNode *q) {
        if (p == NULL || q == NULL) {
            if (p == q)
                return true;
            else
                return false;
        }
        
        
        if (!compareTree(p->left,q->left) || 
                         p->val != q->val || !compareTree(p->right,q->right))
            return false;
       
        return true;
        
    }
};