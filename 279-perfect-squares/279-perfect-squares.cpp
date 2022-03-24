class Solution {
public:
    int f(int k,int targ,vector<vector<int>> &dp){
        
        //cout<<k<<" "<<targ<<endl;
        if(targ==0)
            return 0;
        if(k==1)
            return targ;
        // if(k==0)
        //     return 1e9;
        
        if(dp[k][targ] != -1)
            return dp[k][targ];
        
        int take = 1e9;
        if(k*k <= targ)
            take = 1 + f(k,targ - k*k,dp);
        int notTake = f(k-1,targ,dp);
        
    return dp[k][targ] = min(take,notTake);
}
    
    int numSquares(int n) {
        
        int k = ceil(sqrt(n));
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return f(k,n,dp);
    }
};