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
    void f(TreeNode* root,string cur,vector<string> &res){
        if(!root)
            return;
        if(!root->left && !root->right){
            string s = cur + to_string(root->val);
            res.push_back(s);
        }
        
        string s = cur + to_string(root->val) + "->";
        f(root->left,s,res);
        f(root->right,s,res);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        f(root,"",res);
        return res;
    }
};