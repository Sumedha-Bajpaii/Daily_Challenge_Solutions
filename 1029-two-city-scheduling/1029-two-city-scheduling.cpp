class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b) {
        return (a[0]-a[1]) < (b[0]-b[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
    
        int n = costs.size();
        sort(costs.begin(),costs.end(),cmp);
        
//         for(auto v: costs)
//             cout<<v[0]-v[1]<<" ";
        
        int res=0;
        
        for(int i=0; i<n/2; i++){
            res += costs[i][0];
            res += costs[n-1-i][1];
        }
        return res;
    }
};

