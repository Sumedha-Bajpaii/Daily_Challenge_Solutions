class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        
        unordered_map<int,vector<int>> graph;
        unordered_map<int,int> dep;
        for(int i=0; i<num; i++){
            dep[i]=0;
            graph[i] = vector<int>(0);
        }
        for(auto v: pre){
            graph[v[1]].push_back(v[0]);
            dep[v[0]]++;
        }
        // for(auto p: graph){
        //     cout<<p.first<<" : ";
        //     for(auto nbr: p.second)
        //         cout<<nbr<<" ";
        //     cout<<endl;
        // }
        
        // for(auto it: dep){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        queue<int> q;
        for(auto p: dep){
            if(p.second==0)
                q.push(p.first);
        }
        
        while(q.size()){
            int cur = q.front();
            q.pop();
            for(auto nbr: graph[cur]){
                dep[nbr]-=1;
                if(dep[nbr]==0)
                    q.push(nbr);
            }
        }
        
        for(auto it: dep){
            if(it.second > 0)
                return false;
        }
        return true;   
    }
};