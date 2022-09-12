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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        int flag = 1;
        
        while(q.size()){
            int sz = q.size(), i;
            
            vector<int> level(sz);
            if(flag==1) i=0;
            else    i=sz-1;
                
            for(int j=0; j<sz; j++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left!=NULL)  q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                
                level[i] = node->val;
                i += flag;
            }
            
            ans.push_back(level);
            flag = flag*-1;
        }
        
        return ans;
    }
};