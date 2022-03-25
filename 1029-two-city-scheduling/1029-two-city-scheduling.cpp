class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b) {
        return (a[0]-a[1]) < (b[0]-b[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
    
        sort(costs.begin(),costs.end(),cmp);
        int n = costs.size(), res=0;
        
        for(int i=0; i<n/2; i++){
            res += costs[i][0] + costs[n-1-i][1];
        }
        return res;
    }
};

