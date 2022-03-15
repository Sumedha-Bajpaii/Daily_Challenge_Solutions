class Solution {
public:
    int f(int r,int c,int &m,int &n,vector<vector<int>> &dp){
        if(r==m-1 && c==n-1)
            return 1;

        if(dp[r][c] != -1)
            return dp[r][c];

        int right=0, down=0;
        if(c+1 < n)
            right = f(r,c+1,m,n,dp);
        if(r+1 < m)
            down = f(r+1,c,m,n,dp);

        return dp[r][c] = right + down;
    }
    
    int uniquePaths(int m, int n) {
        // Write your code here.
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(0,0,m,n,dp);
    }
};