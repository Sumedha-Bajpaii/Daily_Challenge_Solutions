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
    void f(TreeNode* root, vector<int>& freq, int& odd,int &path){
        
        if(root==NULL)  return;
        
        if(++freq[root->val]%2 != 0)  odd++;
        else  odd--;
        
        f(root->left,freq,odd,path);
        f(root->right,freq,odd,path);
        
        if(!root->left && !root->right){    //leaf
            if(odd<=1) path++;
        }
        
        if(--freq[root->val]%2 != 0)  odd++;
        else  odd--;
 
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> freq(10,0);
        int odd=0, path=0;
        f(root,freq,odd,path);
        
        return path;
    }
};