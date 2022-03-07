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
 >*/
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        
        unordered_map<int,TreeNode*> mp;
        unordered_map<TreeNode*,bool> root;
        
        for(auto &v:des){
            
            if(mp.find(v[0]) == mp.end()){
                TreeNode* parent = new TreeNode(v[0]);
                mp[v[0]] = parent;
            }
            TreeNode* parent = mp[v[0]];
            
            if(mp.find(v[1]) == mp.end()){
                TreeNode* child = new TreeNode(v[1]);
                mp[v[1]] = child;
             }
            TreeNode* child = mp[v[1]];
            
            if(v[2]==1)
                parent->left = child;
            else
                parent->right = child;
            
            if(root.find(parent)==root.end())
                root[parent] = true;
        
            root[child] = false;
        }
        
        for(auto it: root){
            if(it.second == true){
                //cout<<"root is: "<<it.first->val<<endl;;
                return it.first;
            } 
        }
        return NULL;
    }
};