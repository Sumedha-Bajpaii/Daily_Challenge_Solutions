class Solution {
public:
    int f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i==0){
            for(;j>0; j--){
                if(p[j-1] != '*')
                    return dp[i][j] = 0;
            }
            return dp[i][j] = 1;
        }
        
        if(j==0)
            return dp[i][j] = 0;
        
        if(p[j-1]=='*')
            return dp[i][j] = f(i,j-1,s,p,dp) or f(i-1,j-1,s,p,dp) or f(i-1,j,s,p,dp);
        
        if(p[j-1]=='?')
            return dp[i][j] = f(i-1,j-1,s,p,dp);
        
        if(s[i-1]==p[j-1])
            return dp[i][j] = f(i-1,j-1,s,p,dp);
        else
            return dp[i][j] = 0;
            
    }
    bool isMatch(string s, string p) {
        
        int m=s.size(), n=p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(m,n,s,p,dp);
    }
};