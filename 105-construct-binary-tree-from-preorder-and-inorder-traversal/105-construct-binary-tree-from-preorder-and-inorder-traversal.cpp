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
    TreeNode* f(unordered_map<int,int>& inmap,int ps,int pe, vector<int>& pre, int is, int ie, vector<int>& in){
        if(ps>pe or is>ie)
            return NULL;
        
        TreeNode *root = new TreeNode(pre[ps]);
        int inroot = inmap[pre[ps]];
        int numsLeft = inroot - is;
        
        root->left = f(inmap,ps+1,ps+numsLeft, pre, is,inroot-1, in);
        root->right = f(inmap,ps+numsLeft+1,pe, pre, inroot+1,ie, in);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int> inmap;
        for(int i=0; i<inorder.size(); i++){
            inmap[inorder[i]] = i;
        }
        
        return f(inmap, 0,preorder.size()-1,preorder, 0,inorder.size()-1,inorder);
    }
};