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
    void f(TreeNode *root, string &str){
//         if(root==NULL)
//             return;
        
        str += to_string(root->val);
        
        str += "(";
        if(root->left)
            f(root->left,str);
        str += ")";

        if(root->right){
            str += "(";
            f(root->right,str);
            str += ")";
        }
        else if(root->left == NULL){
            str.pop_back();
            str.pop_back();
        }
    }
    
    string tree2str(TreeNode* root) {
        
        string str = "";
        f(root,str);
        
        // cout<<str<<endl;
        
        return str;
    }
};