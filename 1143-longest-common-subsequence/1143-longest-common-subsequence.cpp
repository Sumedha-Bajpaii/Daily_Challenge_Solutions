class Solution {
public:
    
    
    int f(int i,int j,string& s1,string& s2,vector<vector<int>>& dp)
{
    // if(i == s1.size() && j == s2)
    
    if(i==-1 || j == -1){
            return 0;
    }
        //return s1[i] == s2[j];
    
    if(dp[i][j]!= -1)
        return dp[i][j];
    
    if(s1[i] == s2[j])
    {
        return dp[i][j] = 1 + f(i-1,j-1,s1,s2,dp);
    }
    else
        return dp[i][j] = 0 + max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    
}

    
    int longestCommonSubsequence(string s1, string s2) {
        
        int n = s1.size(),m = s2.size();
        int t = max(n,m);
        vector<vector<int>> dp(t+1,vector<int>(t+1,-1)); 
        return f( n-1, m-1 , s1 ,s2 ,dp);
        
    }
};