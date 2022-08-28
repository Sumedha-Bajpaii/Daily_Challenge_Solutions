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
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*> parent;
        record_parent(root, parent);
        
        //bfs
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);
        int dist=0;
        
        while(q.size()){
            if(dist==k)
                break;
            dist++;
            
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto node = q.front();
                q.pop();

                if(parent.find(node)!=parent.end() && vis.find(parent[node])==vis.end()){
                    q.push(parent[node]);
                    vis.insert(parent[node]);
                }
                if(node->left && vis.find(node->left)==vis.end()){
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right && vis.find(node->right)==vis.end()){
                    q.push(node->right);
                    vis.insert(node->right);
                }
            }
        }
        
        vector<int> res;
        while(q.size()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};