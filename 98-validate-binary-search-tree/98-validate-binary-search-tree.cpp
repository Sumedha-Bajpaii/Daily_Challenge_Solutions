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
    bool f(TreeNode* root, long minn, long maxx){
        
        if(root==NULL)
            return true;
        
        if(root->val <= minn  ||  root->val >= maxx){
            return false;
        }
        bool left = f(root->left, minn, root->val);
        bool right = f(root->right, root->val, maxx);
        
        return left&&right;
    }
    
    bool isValidBST(TreeNode* root) {
        return f(root,LONG_MIN,LONG_MAX);
    }
};