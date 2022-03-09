class Solution {
public:
    int f(int ind, int amt, vector<int> &A, vector<vector<int>> &dp){
        
        if(ind == -1){
            if(amt==0)
                return 0;
            else
                return INT_MAX-20;
        }
        if(dp[ind][amt] != -1)
            return dp[ind][amt];
        
        int take=INT_MAX-20, nottake=INT_MAX-20;
    
        nottake = f(ind-1,amt,A,dp);
        if(A[ind]<=amt)
            take = 1+f(ind,amt-A[ind],A,dp);
        
        return dp[ind][amt] = min(take,nottake);
    }
    int coinChange(vector<int>& A, int amt) {
        
        int n = A.size();
        vector<vector<int>> dp(n+1,vector<int>(amt+1,-1));
        int res = f(n-1,amt,A,dp);
        
        if(res<INT_MAX-20)
            return res;
        else
            return -1;
    }
};