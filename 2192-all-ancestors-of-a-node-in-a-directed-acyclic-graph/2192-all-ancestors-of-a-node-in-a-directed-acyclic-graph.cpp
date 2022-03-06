class Solution {
public:
    void dfs(int node,map<int,vector<int>> &mp,vector<bool> &visit){
        visit[node]=true;
        for(auto j: mp[node]){
            if(visit[j]!=true)
                dfs(j,mp,visit);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n,vector<int>());
        map<int,vector<int>> mp;
        
        for(auto &v: edges){
            mp[v[0]].push_back(v[1]);
        }
        
        for(auto it: mp){
            int i=it.first;
            vector<bool> visit(n,false);
            dfs(i,mp,visit);
            
            for(int j=0; j<n; j++){
                if(visit[j]==true && i!=j)
                    ans[j].push_back(i);
            }
        }
        
        return ans;
    }
};