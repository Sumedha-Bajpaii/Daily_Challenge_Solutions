class Solution {
public:
    int mod = 1e9+7;
    int f(int n,int t, int k,vector<vector<int>>& dp){
        if(t==0){
            if(n==0)    return 1;
            else    return 0;
        }
        if(n==0 || t<0) return 0;
        
        if(dp[n][t] != -1)
            return dp[n][t];
        
        int ans=0;
        for(int i=1; i<=k; i++){
            ans = (ans%mod + f(n-1,t-i,k,dp)%mod)%mod;
        }
        return dp[n][t] = ans;
    }
    
    int numRollsToTarget(int n, int k, int t) {
        
        vector<vector<int>> dp(n+1,vector<int>(t+1,-1));
        return f(n,t,k,dp);
    }
};