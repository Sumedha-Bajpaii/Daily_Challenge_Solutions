class Solution {
public:
    
    bool isCyclic(int node,vector<vector<int>>& adj,vector<int>& vis, vector<int>& dfsvis){
        
        vis[node] = 1;
        dfsvis[node] = 1;
        
        for(auto it: adj[node]){
            if(vis[it]==0){
                if(isCyclic(it,adj,vis,dfsvis)==true)
                    return true;
            }
            else if(dfsvis[it]==1)
                return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    
    bool canFinish(int num, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(num);
        
        for(auto v:pre){
            adj[v[1]].push_back(v[0]);
        }
        vector<int> vis(num,0), dfsvis(num,0), res;
        
        // dfsvis --> true for nodes in current recursion stack
        for(int i=0; i<num; i++){
            if(vis[i]==0){
                if(isCyclic(i,adj,vis,dfsvis) == true)
                    return false;
            }
        }
     
        return true;

    }
};