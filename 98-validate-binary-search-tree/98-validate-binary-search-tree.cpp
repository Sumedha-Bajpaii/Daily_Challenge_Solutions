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
    bool f(TreeNode* root,long long mini, long long maxi)
    {
        if(root==NULL)
            return true;
        if(root->val<=mini || root->val>=maxi)
            return false;
        
        //if(mini<root->val && root->val<maxi)
        //ok
        
        return f(root->left, mini, root->val*1LL) && f(root->right, root->val, maxi*1LL);
        
    }
    bool isValidBST(TreeNode* root) {
        
        return f(root,LLONG_MIN,LLONG_MAX);
        
    }
};