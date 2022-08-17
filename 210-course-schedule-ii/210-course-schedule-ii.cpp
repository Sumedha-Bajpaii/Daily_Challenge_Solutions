class Solution {
public:
    bool isCyclic(int node,vector<vector<int>>& adj,vector<int>& vis, vector<int>& dfsvis, vector<int>& res){
        
        vis[node] = 1;
        dfsvis[node] = 1;
        
        for(auto it: adj[node]){
            if(vis[it]==0){
                if(isCyclic(it,adj,vis,dfsvis,res)==true)
                    return true;
            }
            else if(dfsvis[it]==1)
                return true;
        }
        dfsvis[node] = 0;
        res.push_back(node);
        return false;
    }
    
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(num);
        
        for(auto v:pre){
            adj[v[1]].push_back(v[0]);
        }
        vector<int> vis(num,0), dfsvis(num,0), res;
        
        // dfsvis --> true for nodes in current recursion stack
        for(int i=0; i<num; i++){
            if(vis[i]==0){
                if(isCyclic(i,adj,vis,dfsvis,res) == true)
                    return {};
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};