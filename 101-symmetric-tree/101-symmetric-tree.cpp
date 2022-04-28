/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool f(TreeNode *old, TreeNode *neww){
        if(!old && !neww)
            return true;
        if(!old || !neww)
            return false;
        if(old->val != neww->val)
            return false;
        return f(old->left, neww->right) && f(old->right, neww->left);
    }
    bool isSymmetric(TreeNode* root) {
        
        return f(root->left,root->right);
    }
};