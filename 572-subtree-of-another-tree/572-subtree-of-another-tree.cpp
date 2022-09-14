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
    bool same(TreeNode* root,TreeNode* sroot){
        if(root==NULL && sroot==NULL)
            return true;
        if(root==NULL || sroot==NULL)
            return false;
        if(root->val!=sroot->val)
            return false;
        
        return same(root->left,sroot->left) && same(root->right,sroot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* sroot) {
         if(root==NULL)
            return false;
        return same(root,sroot) || isSubtree(root->left,sroot) || isSubtree(root->right,sroot);
    }
};