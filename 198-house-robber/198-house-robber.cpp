class Solution {
public:
    int f(int i, int sum, vector<int>& a,vector<vector<int>> &dp){
        if(i>=a.size())
            return sum;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        return dp[i][sum] = max(f(i+2, sum+a[i], a,dp), f(i+1, sum, a,dp));
        
    }
    int rob(vector<int>& nums) {
        
        int total =0;
        for(auto i: nums)
            total += i;
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(total+1,-1));
        return f(0,0,nums,dp);
        
    }
};