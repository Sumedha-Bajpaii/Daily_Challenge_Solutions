class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    
    int dfs(int i, int j,int last, vector<vector<int>>& mat,vector<vector<int>> &dp){
        
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size())
            return 0;
        if(mat[i][j]==-2 || mat[i][j]<=last)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int temp = mat[i][j];
        mat[i][j] = -2;
        
        int res = 0;
        for(auto &d: dir){
            res = max(res, dfs(i+d.first, j+d.second, temp,mat,dp));
        }
        
        mat[i][j] = temp;
        return dp[i][j] = res+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        
        int m=mat.size(), n=mat[0].size();
        int ans = 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, dfs(i,j,-1,mat,dp));
                cout<<ans<<" ";
            }
        }
        
        return ans;
    }
};