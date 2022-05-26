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
    
    long f(TreeNode* root, long total, long &prod){
        if(!root)
            return 0;
        long lsum = f(root->left, total, prod);
        long rsum = f(root->right, total, prod);
        long curSum = lsum + rsum + root->val;
        
        prod = max(prod, curSum*(total-curSum) );
        
        return curSum;
    }
    
    int maxProduct(TreeNode* root) {
        
        long res = 0;
        long total = f(root,0,res);
        
        f(root,total,res);
        return res%mod;
    }
};