class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& path,vector<int>& res){
        
        // cout<<node<<" ";
        vis[node] = 1;
        path[node] = 1;
        
        for(auto it: adj[node]){
            if(vis[it]==0){
                if(dfs(it,adj,vis,path,res) == true)
                    return true;
            }
            else if(path[it]==1){
                return true;
            }
        }
        
        path[node] = 0;
        res.push_back(node);
        return false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(n);
        
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<int> vis(n,0),path(n,0), res;
        
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis,path,res)==true)       //there is a cycle
                    return {};
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};