class Solution {
public:
    bool dfs(int u,int parent,vector<int>& vis,vector<vector<int>>& graph){
        
        if(parent==2)
            vis[u] = -1;    //first color
        else
            vis[u] = parent*-1;
        
        for(auto it: graph[u]){
            if(vis[it]==0){
                if(dfs(it,vis[u],vis,graph)==false)
                    return false;
            }
            else if(vis[it]==vis[u])
                return false;
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> vis(n,0); //0: not visited    1/-1: two colors
        
        for(int i=0; i<n; i++){
            if(vis[i]==0){     //not visited
                if(dfs(i,2,vis,graph)==false)
                    return false;
            }
        }
        return true;
    }
};