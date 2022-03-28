class Solution {
public:
	int f(string &s1,string &s2,int m,int n,vector<vector<int>> &dp)
	{
	    if(m==0 || n==0)
	        return 0;
	   
	    if(dp[m][n] != -1)
	        return dp[m][n];
	        
	    if(s1[m-1]==s2[n-1])
	        return dp[m][n] = 1 + f(s1,s2,m-1,n-1,dp);
	        
	    return dp[m][n] = max(f(s1,s2,m-1,n,dp), f(s1,s2,m,n-1,dp));
	}
    
    int minDistance(string s1, string s2) {
        
        int m = s1.size();
	    int n = s2.size();
	    
	    vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
	    
	    int lcsLen = f(s1,s2,m,n,dp);
	    return m-lcsLen + n-lcsLen;
    }
};