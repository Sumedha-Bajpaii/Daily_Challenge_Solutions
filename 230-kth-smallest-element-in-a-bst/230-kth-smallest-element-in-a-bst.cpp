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
    int ans, cur;
    
    void f(TreeNode* node, int k){
        
        if(!node){
            if(cur==-1)
                cur=0;
            return;
        }
        
        f(node->left,k);
        
        cur++;
        if(cur==k){
            ans = node->val;
            return;
        }
        
        f(node->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        cur = -1;
        f(root,k);
        return ans;
    }
};