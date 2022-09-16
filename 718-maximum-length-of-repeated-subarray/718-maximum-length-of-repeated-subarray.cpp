class Solution {
public:
    int ans=0;
    int f(int i,int j,vector<int>& A,vector<int>& B,vector<vector<int>>& dp){
        
        if(i<0 || j<0)  return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int cur=0;
        if(A[i]==B[j]){
            cur = 1 + f(i-1,j-1,A,B,dp);
        }
        ans = max(ans,cur);
        f(i-1,j,A,B,dp);
        f(i,j-1,A,B,dp);
        
        return dp[i][j] = cur;
    }
    
    int findLength(vector<int>& A, vector<int>& B) {
        
        int n=A.size(), m=B.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        f(n-1,m-1,A,B,dp);
        return ans;
    }
};