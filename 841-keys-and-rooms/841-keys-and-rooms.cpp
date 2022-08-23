class Solution {
public:
    void dfs(int v, vector<vector<int>>& adj, vector<int>& vis){
        vis[v] = 1;
        for(auto u: adj[v]){
            if(vis[u]!=1){
                dfs(u,adj,vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<vector<int>> adj(n);
        
        for(int i=0; i<n; i++){
            adj[i] = rooms[i];
        }
        
        vector<int> vis(n,0); 
        dfs(0,adj,vis);
        
        for(auto x: vis){
            if(x==0)
                return false;
        }
        
        return true;
    }
};