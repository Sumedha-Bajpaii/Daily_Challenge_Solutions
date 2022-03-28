class Solution {
public:
    int f(int i, int targ,vector<vector<int>> &dp)
    {
        if(targ==0 || i==0)
            return 1;
        if(dp[i][targ] != -1 || dp[targ][i] != -1)
            return dp[i][targ];
        
        int take = 1;
        if(i<=targ)
            take = i*f(i,targ-i,dp);
        
        int notTake = f(i-1,targ,dp);
        
        return max(take,notTake);
    }
    
    int integerBreak(int n) 
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(n-1,n,dp);
    }
};