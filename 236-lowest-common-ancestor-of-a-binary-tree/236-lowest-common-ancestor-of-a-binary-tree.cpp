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
    bool f(TreeNode* root, TreeNode* t, vector<TreeNode*> &path){
        if(!root)
            return false;
        path.push_back(root);
        
        if(root==t)
            return true;
        
        if( f(root->left,t,path) || f(root->right,t,path) )
            return true;
        
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> pTak, qTak;
        f(root,p,pTak);
        f(root,q,qTak);
        
        int n = min(pTak.size(), qTak.size());
        TreeNode* ans = root;
        
        for(int i=0; i<n; i++){
            if(pTak[i] == qTak[i])
                ans = pTak[i];
            else
                return ans;
        }
        return ans;
    }
};