class Solution {
public:
    int f(vector<int>& s, int ind, int M, vector<vector<int>> &dp)
    {
        if(ind == s.size())
            return 0;
        
        if(dp[ind][M] != -1)
            return dp[ind][M];
        
        
        int notTake = f(s,ind+1,M,dp);
        int take = s[ind]*M + f(s,ind+1,M+1,dp);
        
        return dp[ind][M] = max(take,notTake);
        
    }
    int maxSatisfaction(vector<int>& s) {
        
        sort(s.begin(),s.end());
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
        return f(s,0,1,dp);
    }
};