class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(num);
        
        for(auto v:pre){
            adj[v[1]].push_back(v[0]);
        }
        
        vector<int> inDegree(num,0);
        
        for(int u=0; u<num; u++){
            for(auto v: adj[u]){
                inDegree[v]++;
            }
        }
        
        queue<int> q;
        for(int u=0; u<num; u++){
            if(inDegree[u]==0){
                q.push(u);
            }
        }
        
        vector<int> res;
        while(q.size()){
            int u = q.front(); q.pop();
            res.push_back(u);
            
            for(auto v: adj[u]){
                inDegree[v]--;
                if(inDegree[v]==0){
                    q.push(v);
                }
            }
        }
        
        if(res.size() == num)
            return true;
        return false;
    }
};