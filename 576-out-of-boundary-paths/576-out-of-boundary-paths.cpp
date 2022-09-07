class Solution {
public:
    int mod = 1e9+7;
    int dfs(int i,int j, int maxx,int m,int n,vector<vector<vector<int>>> &dp){
        
        if(i<0 || j<0 || i>=m || j>=n)
            return 1;
        if(maxx==0)
            return 0;
        if(dp[i][j][maxx] != -1)
            return dp[i][j][maxx];
        
        int l=0,r=0,u=0,d=0;
        l = dfs(i,j-1, maxx-1,m,n,dp);
        r = dfs(i,j+1, maxx-1,m,n,dp);
        u = dfs(i-1,j, maxx-1,m,n,dp);
        d = dfs(i+1,j, maxx-1,m,n,dp);
        
        
        return dp[i][j][maxx] = ((l+r)%mod + (u+d)%mod)%mod;
        // return dp[i][j][maxx] = ( (l+r+u)%mod + d)%mod;
        // return dp[i][j][maxx] = (l+r+u+d)%mod;        
    }
    
    int findPaths(int m, int n, int maxx, int sr, int sc) {
        
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(51,-1)));
        return dfs(sr,sc,maxx,m,n,dp);
    }
};