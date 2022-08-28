/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void record_parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent){
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }
    
    void dfs(TreeNode* node,unordered_map<TreeNode*,TreeNode*>& parent, int dist, int k,unordered_set<TreeNode*>& vis, vector<int>& res){
        
        if(dist==k){
            res.push_back(node->val);
            return;
        }
        vis.insert(node);
        //parent left right
        
        if(parent.find(node)!=parent.end() && vis.find(parent[node])==vis.end()){
            dfs(parent[node],parent,dist+1,k,vis,res);
        }
        if(node->left && vis.find(node->left)==vis.end()){
            dfs(node->left, parent, dist+1,k,vis,res);
        }
        if(node->right && vis.find(node->right)==vis.end()){
            dfs(node->right, parent, dist+1,k,vis,res);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*> parent;
        record_parent(root, parent);
        
        unordered_set<TreeNode*> vis;
        vector<int> res;
        dfs(target,parent,0,k,vis,res);
        
        return res;
    }
};