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
    TreeNode *first,*last,*prev;
public:
    void solve(TreeNode* root){
        if(root==NULL)
            return;
        solve(root->left);
        
        if(prev!=NULL && root->val<prev->val)        //violation
        {
            if(first == NULL)
                first=prev;
            last = root;
        }
        
        prev = root;
        solve(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        
        if(root==NULL)  return;
        
        first = last = prev = NULL;
      
        solve(root);
        
        swap(first->val,last->val);
    }
};