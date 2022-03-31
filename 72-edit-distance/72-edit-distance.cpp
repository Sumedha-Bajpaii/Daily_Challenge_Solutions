class Solution {
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        
        if(j==0)
            return i;
        if(i==0)
            return j;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i-1] != t[j-1]){
            int del = 1 + f(i-1,j,s,t,dp);
            int repl = 1 + f(i-1,j-1,s,t,dp);
            int ins = 1 + f(i,j-1,s,t,dp);
            
            return dp[i][j] = min({del,repl,ins});
        }
        return dp[i][j] = f(i-1,j-1,s,t,dp);
    }
    
    int minDistance(string s, string t) {
        
        int m=s.size(), n=t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        return f(m,n,s,t,dp);
    }
};