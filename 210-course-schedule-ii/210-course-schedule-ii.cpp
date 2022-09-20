class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(n);
        
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<int> inDegree(n,0);
        for(int i=0; i<n; i++){
            for(auto it: adj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDegree[i]==0)
                q.push(i);
        }
        
        vector<int> res;
        while(q.size()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(auto it: adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0)
                    q.push(it);
            }
        }
        
        if(res.size() < n)
            return {};
        return res;
    }
};