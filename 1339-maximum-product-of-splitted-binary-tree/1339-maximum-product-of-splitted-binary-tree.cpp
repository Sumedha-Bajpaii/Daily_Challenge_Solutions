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
    int mod = 1e9 + 7;
    long f(TreeNode* root){
        if(!root)
            return 0;
        long lsum = f(root->left);
        long rsum = f(root->right);
        
        return lsum + rsum + root->val;
    }
    
    long g(TreeNode* root, long total, long &prod){
        if(!root)
            return 0;
        long lsum = g(root->left, total, prod);
        long rsum = g(root->right, total, prod);
        
        prod = max(prod, lsum*(total-lsum) );
        prod = max(prod, rsum*(total-rsum) );
        
        return lsum + rsum + root->val;
    }
    
    int maxProduct(TreeNode* root) {
        
        long total = f(root);
        // cout<<total;
        long res = 0;
        g(root,total,res);
        return res%mod;
    }
};