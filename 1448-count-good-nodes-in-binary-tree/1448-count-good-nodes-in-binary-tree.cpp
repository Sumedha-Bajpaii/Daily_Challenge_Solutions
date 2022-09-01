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
    int f(TreeNode* root, int maxx){
        if(root==NULL)
            return 0;
        
        int pass=0;
        maxx = max(maxx,root->val);
        if(root->val >= maxx)
            pass = 1;
        
        return f(root->left,maxx) + f(root->right,maxx) + pass;
    }
    int goodNodes(TreeNode* root) {
        
        return f(root,root->val);
    }
};