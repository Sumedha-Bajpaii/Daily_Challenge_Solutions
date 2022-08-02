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
    
    long f(TreeNode* root, long total, long &ans){
        if(root==NULL)
            return 0;
        
        long ls = f(root->left,total,ans);
        long rs = f(root->right,total,ans);
        
        ans = max(ans, ls*(total-ls));
        ans = max(ans, rs*(total-rs));
        
        return ls + rs + root->val;
    }
    
    int maxProduct(TreeNode* root) {
        
        int mod = 1e9+7;
        long ans = 0;
        
        long total = f(root,0,ans);
        //cout<<ans<<endl;
        f(root,total,ans);
        
        return ans%mod;
    }
};