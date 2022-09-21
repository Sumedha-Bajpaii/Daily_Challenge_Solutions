class Solution {
public:
    int f(int i,int amt,vector<int>& coins,vector<vector<int>>& dp){
        if(amt==0)
            return 0;
        if(i==-1)
            return 1e9;
        
        if(dp[i][amt] != -1)
            return dp[i][amt];
        
        int tk=1e9,nt=1e9;
        if(coins[i] <= amt){
            tk = 1 + f(i,amt-coins[i],coins,dp);
        }
        nt = f(i-1,amt,coins,dp);
        
        return dp[i][amt] = min(tk,nt);
    }
    
    int coinChange(vector<int>& coins, int amt) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amt+1,-1));
        int res = f(n-1,amt,coins,dp);
        
        if(res >= 1e9)
            return -1;
        return res;
    }
};