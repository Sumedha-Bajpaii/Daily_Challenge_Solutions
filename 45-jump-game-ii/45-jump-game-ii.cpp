class Solution {
public:
    int f(int i,vector<int> &nums,vector<int> &dp){
        if(i>=nums.size()-1){
            return 0;
        }
        if(dp[i] != -1)
            return dp[i];
        
        int ans=1e9;
        for(int j=1; j<=nums[i]; j++){
            int t = 1 + f(i+j,nums,dp);
            ans = min(ans,t);
        }
        
        return dp[i] = ans;
    }
    
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};