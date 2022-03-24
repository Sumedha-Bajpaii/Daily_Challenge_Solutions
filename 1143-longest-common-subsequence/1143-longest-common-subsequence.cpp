class Solution {
public:
    int f(string &s1,string &s2, int i, int j, vector<vector<int>> &dp){
        if(i==0 || j==0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i-1]==s2[j-1])
            return dp[i][j] = 1+f(s1,s2,i-1,j-1,dp);
        return dp[i][j] = max(f(s1,s2,i,j-1,dp),f(s1,s2,i-1,j,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        
        int m=s1.size(), n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(s1,s2,m,n,dp);
        
    }
};