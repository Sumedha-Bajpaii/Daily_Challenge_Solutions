class Solution {
public:
    int minimumTotal(vector<vector<int>>& T) {
        
        int n = T.size();
        vector<vector<int>> dp(n,vector<int>(n));
        
        for(int j=0; j<n; j++)
            dp[n-1][j] = T[n-1][j];
        
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                dp[i][j] = T[i][j] + min(dp[i+1][j], dp[i+1][j+1]);  
            }
        }
        
        return dp[0][0];
    }
};