class Solution {
public:
    int f(int i,int j,string s1, string s2, vector<vector<int>>& dp){
        if(i==-1)
            return j+1;
        if(j==-1)
            return i+1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i]==s2[j]){
            return f(i-1,j-1,s1,s2,dp);
        }
        int x = f(i-1,j,s1,s2,dp);
        int y = f(i,j-1,s1,s2,dp);
        
        return dp[i][j] = 1 + min(x,y);
    }
    int minDistance(string s1, string s2) {
        
        int n1=s1.size(), n2=s2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return f(n1-1,n2-1,s1,s2,dp);
    }
};