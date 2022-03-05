class Solution {
public:
    int f(int idx, vector<int> &A, vector<int> &dp){
        if(idx<0)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int take = A[idx] + f(idx-2,A,dp);
        int nottake = f(idx-1,A,dp);
        
        return dp[idx] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return f(n-1,nums,dp);
    }
};