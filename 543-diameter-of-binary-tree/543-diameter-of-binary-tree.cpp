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
    int f(TreeNode* root, int &dm){
        
        if(root==NULL)
            return 0;
        
        int leftDepth = f(root->left,dm);
        int rightDepth = f(root->right,dm);
        dm = max(dm, leftDepth+rightDepth);
        
        return 1 + max(leftDepth,rightDepth);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int dm=0;
        f(root,dm);
        
        return dm;
    }
};