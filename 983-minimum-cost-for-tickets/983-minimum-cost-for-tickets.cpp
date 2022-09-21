class Solution {
public:
    int f(int i,int covered,vector<int>& days,vector<int>& costs,vector<vector<int>>& dp){
        
        if(i >= days.size())
            return 0;
        
        if(dp[i][covered] != -1)
            return dp[i][covered];
        
        if(days[i] <= covered){
            return dp[i][covered] = f(i+1,covered,days,costs,dp);
        }
        
        //days[i] -> today
        int c1 = costs[0] + f(i+1, days[i]+1-1, days,costs,dp);
        int c7 = costs[1] + f(i+1, days[i]+7-1, days,costs,dp);
        int c30 = costs[2] + f(i+1, days[i]+30-1, days,costs,dp);
        
        return dp[i][covered] = min({c1,c7,c30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<vector<int>> dp(days.size(),vector<int>(400,-1));
        return f(0,0,days,costs,dp);
    }
};