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
    TreeNode* f(TreeNode* node, int t){
        
        if(!node)
            return NULL;
        
        node->left = f(node->left,t);
        node->right = f(node->right,t);
        
        if(!node->left && !node->right){
            if(node->val==t)
                return NULL;
        }
        return node;
    }
    
    
    TreeNode* removeLeafNodes(TreeNode* root, int t) {
        
        return f(root,t);
    }
};