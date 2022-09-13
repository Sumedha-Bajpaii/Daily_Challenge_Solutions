class Solution {
public:
    bool bfs(int u,vector<int>& vis,vector<vector<int>>& graph){
        
        queue<int> q;
        q.push(u);
        vis[u] = 0;
        
        while(q.size()){
            int v = q.front();
            q.pop();
            
            for(auto it: graph[v]){
                if(vis[it] == -1){
                    q.push(it);
                    vis[it] = !vis[v];
                }
                else if(vis[it] == vis[v])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> vis(n,-1); //-1: not visited    1/0: two colors
        
        for(int i=0; i<n; i++){
            if(vis[i]==-1){     //not visited
                if(bfs(i,vis,graph)==false)
                    return false;
            }
        }
        return true;
    }
};