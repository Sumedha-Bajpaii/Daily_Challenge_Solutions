class Solution {
public:
    int f(int i, int j, int row, vector<vector<int>>& T,vector<vector<int>>& dp){
        if(i == row-1)
            return T[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = f(i+1,j,row,T,dp);
        int downRight = f(i+1,j+1,row,T,dp);
        
        return dp[i][j] = T[i][j] + min(down,downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return f(0,0,n,triangle,dp);
    }
};