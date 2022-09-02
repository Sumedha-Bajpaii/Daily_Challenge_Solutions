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
private:
    TreeNode *first,*last;
public:
    void solve(TreeNode *&prev, TreeNode* root){
        if(root==NULL)
            return;
        solve(prev,root->left);
        
        if(prev!=NULL && root->val<prev->val)        //violation
        {
            if(first == NULL)
                first=prev;
            last = root;
        }
        
        prev = root;
        solve(prev,root->right);
    }
    
    void recoverTree(TreeNode* root) {
        
        if(root==NULL)  return;
        
        first = last = NULL;
        TreeNode *prev=NULL;
        solve(prev,root);
        
        swap(first->val,last->val);
    }
};