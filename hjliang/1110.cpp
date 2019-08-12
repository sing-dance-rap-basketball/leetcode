/**
 * 1110. Delete Nodes And Return Forest
 * Given the root of a binary tree, each node in the tree has a distinct value.
 * After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
 * Return the roots of the trees in the remaining forest.  You may return the result in any order.
 */

/**
 * Runtime: 28 ms, faster than 44.29% of C++ online submissions for Delete Nodes And Return Forest.
 * Memory Usage: 30 MB, less than 100.00% of C++ online submissions for Delete Nodes And Return Forest.
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ret;
        root = reDelNodes(root, to_delete, ret);
        
        if(root != NULL)
            ret.push_back(root);
        return ret;
    }
    
    bool isInDelVec(int val, vector<int> to_delete) {
        int size = to_delete.size();
        for(int i = 0; i < size; ++i) {
            if (val == to_delete[i]) {
                swap(to_delete[i], to_delete[size-1]);
                to_delete.pop_back();
                return true;
            }
        } 
        return false;
    }
    
    TreeNode* reDelNodes(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& ret) {
        if (root == NULL)
            return NULL;
        
        root->left = reDelNodes(root->left, to_delete, ret);
        root->right = reDelNodes(root->right, to_delete, ret);
        
        if (isInDelVec(root->val, to_delete)) {
            if (root->left != NULL) ret.push_back(root->left);
            if (root->right != NULL) ret.push_back(root->right);
            return NULL;
        }
        else
            return root;
    }
};