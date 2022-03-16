class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>>& M,vector<vector<int>> &dp){
        
        if(j<0 || j>=n)
            return INT_MAX;
        
        if(i==n-1)
            return dp[i][j] = M[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int dl = f(i+1,j-1,n,M,dp);
        int d = f(i+1,j,n,M,dp);
        int dr = f(i+1,j+1,n,M,dp);
        
        return dp[i][j] = M[i][j] + min(dl,min(d,dr));
    }
    
    int minFallingPathSum(vector<vector<int>>& M) {
        
        int n = M.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int j=0; j<n; j++)
            f(0,j,n,M,dp);
        
        return *min_element(dp[0].begin(), dp[0].end());
        
    }
};