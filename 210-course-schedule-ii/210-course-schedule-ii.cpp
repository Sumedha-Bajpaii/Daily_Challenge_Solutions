class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        
        vector<int> order;
        
        unordered_map<int,vector<int>> graph;
        unordered_map<int,int> dep;
        
        for(int i=0; i<num; i++){
            graph[i] = vector<int>(0);
            dep[i] = 0;
        }
        for(auto v: pre){
            graph[v[1]].push_back(v[0]);
            dep[v[0]]++;
        }
        
        queue<int> q;
        for(auto p: dep){
            if(p.second==0)
                q.push(p.first);
        }
        
        while(q.size()){
            int cur = q.front();
            q.pop();
            for(auto nbr: graph[cur]){
                dep[nbr]--;
                if(dep[nbr]==0)
                    q.push(nbr);
            }
            order.push_back(cur);
        }
        
        for(auto p: dep){
            if(p.second>0)
                return {};
        }
   
        return order;
    }
};