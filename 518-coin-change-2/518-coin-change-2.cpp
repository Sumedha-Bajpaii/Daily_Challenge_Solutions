class Solution {
public:
    int f(int amt,int i,vector<int> &coins,vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(amt%coins[i] == 0)
                return 1;
            return 0;
        }
        if(dp[amt][i] != -1)
            return dp[amt][i];
        
        int notTake = f(amt,i-1,coins,dp);
        
        int take = 0;
        if(coins[i]<=amt)
            take = f(amt-coins[i],i,coins,dp);
        
        return dp[amt][i] = take + notTake;
        
    }
    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amt+1,vector<int>(n+1,-1));
        
        return f(amt,n-1,coins,dp);
    }
};