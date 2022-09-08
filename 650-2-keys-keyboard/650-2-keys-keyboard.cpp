// at each step we have 2 options
// paste   --> operation += 1   --> len += prev
// copy paste  --> operation += 2   --> len += len

class Solution {
public:
    int f(int len, int prev, int n,vector<vector<int>> &dp){
        if(len > n)
            return 1e9;
        if(len == n)
            return 0;
        
        if(dp[len][prev] != -1)
            return dp[len][prev];
        
        int p = 1 + f(len+prev, prev, n,dp);
        int cp = 2 + f(len+len, len, n,dp);
        return dp[len][prev] = min(p,cp);
    }
    
    int minSteps(int n) {
        if(n==1)    return 0;
        vector<vector<int>> dp(2*n,vector<int>(2*n,-1));
        return 1 + f(1,1,n,dp);
    }
};
